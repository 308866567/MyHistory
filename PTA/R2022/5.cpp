#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N = 40 + 5;
ll n, q;


class segmentTree
{
	public:
		struct node
		{
			ll sum = 0;
			ll minn = 1e9;
			int l, r;
			ll mark = 0;
		} t[4 * N];
		// ����
//	segmentTree(ll *A)
//	{
//		a = A;
//	}
		ll *a;
		inline ll ls(ll p)
		{
			return p << 1;
		}
		inline ll rs(ll p)
		{
			return p << 1 | 1;
		}
		inline void push_up(ll p) // �ӵ�����
		{
			t[p].sum = t[ls(p)].sum + t[rs(p)].sum;
			t[p].minn = min(t[ls(p)].minn, t[rs(p)].minn);
		}
		inline void push_down(ll p, ll l, ll r) // ����
		{
			if (t[p].mark == 0)
				return;
			ll mid = (l + r) / 2;
			// ��Сֵ
			t[ls(p)].minn += t[p].mark;
			t[rs(p)].minn += t[p].mark;
			// ��
			t[ls(p)].sum += t[p].mark * (mid - l + 1);
			t[rs(p)].sum += t[p].mark * (r - mid);
			t[ls(p)].mark += t[p].mark;
			t[rs(p)].mark += t[p].mark;
			t[p].mark = 0;
		}
		// ��ʼ��
		void build(ll p = 1, ll l = 1, ll r = n)
		{
			t[p].l = l;
			t[p].r = r;
			if (l == r)
			{
				t[p].sum = a[l];
				t[p].minn = a[l];
				return;
			}
			ll mid = (l + r) / 2;
			build(ls(p), l, mid);
			build(rs(p), mid + 1, r);
			push_up(p);
		}
		// �����޸�
		void update(ll tl, ll tr, ll k, ll p = 1, ll l = 1, ll r = n)
		{
			if (l >= tl && r <= tr)
			{
				t[p].sum += k * (r - l + 1);
				t[p].mark += k;
				t[p].minn += k;
				return;
			}
			push_down(p, l, r);
			ll mid = (l + r) / 2;
			if (mid >= tl)
			{
				update(tl, tr, k, ls(p), l, mid);
			}
			if (mid < tr)
			{
				update(tl, tr, k, rs(p), mid + 1, r);
			}
			push_up(p);
			return;
		}
		// ����Ͳ�ѯ
		ll query(ll tl, ll tr, ll p = 1, ll l = 1, ll r = n)
		{
			if (l >= tl && r <= tr)
			{
				return t[p].sum;
			}
			push_down(p, l, r);
			ll sum = 0;
			ll mid = (l + r) / 2;
			if (mid >= tl)
			{
				sum += query(tl, tr, ls(p), l, mid);
			}
			if (mid < tr)
			{
				sum += query(tl, tr, rs(p), mid + 1, r);
			}
			return sum;
		}
		// ����������Сֵ
		ll querymin(ll tl, ll tr, ll p = 1, ll l = 1, ll r = n)
		{
			if (l >= tl && r <= tr)
			{
				return t[p].minn;
			}
			push_down(p, l, r);
			ll res = 1e9;
			ll mid = (l + r) / 2;
			if (mid >= tl)
			{
				res = querymin(tl, tr, ls(p), l, mid);
			}
			if (mid < tr)
			{
				res = min(res, querymin(tl, tr, rs(p), mid + 1, r));
			}
			return res;
		}
};

segmentTree T;



class Q
{
	public:
		int l, r;
		int val;
		void set()
		{
			int a, b;
			cin >> a >> b;
			l = min(a, b);
			r = max(a, b);
		}
		//�Ҷ˵��С����
		friend bool operator<(Q &a, Q&b)
		{
			if (a.r == b.r)
				return a.l < b.l;
			else
				return a.r < b.r;
		}
} arr[N];

void out()
{
	for (int i = 1; i < n; i++)
	{
		cout << T.querymin(i, i, 1, 1, n - 1) << " ";
	}
	cout << "\n";
}



int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	ll A[N];
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> A[i];
	}

	T.a = A;
	T.build(1, 1, n - 1);


	//TODOС����������©


	for (int i = 0; i < q; i++)
	{
		arr[i].set();
	}
	ll ans = 0;
	//̰�ĵ������Ĳ��ཻ��������Ŀ
	sort(arr, arr + q);
//	out();
	ll t=0;
	for (int i = 0; i < q; i++)
	{
		cout<<arr[i].l<<" "<<arr[i].r<<" ";
		t = T.querymin(arr[i].l + 1, arr[i].r, 1, 1, n-1); //������Сֵ
		cout<<t<<"\n";
		out();
		if (t > 0)
		{
			T.update(arr[i].l + 1, arr[i].r, -t, 1, 1, n-1); //�����ȥ
			ans += t;
		}
		out();
	}
	cout << ans;
	return 0;
}
