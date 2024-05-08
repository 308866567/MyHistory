#include <iostream>
typedef long long ll;
using namespace std;
const ll N = 1e5 + 5;
ll n, m;
ll a[N];
class segmentTree
{
public:
	struct node
	{
		ll sum = 0;
		//			int minn = 0;
		//			int l, r;
		ll mark = 0;
	} t[4 * N];
	segmentTree(ll *A)
	{
		a = A;
	}
	ll *a;
	inline ll ls(ll p)
	{
		return p << 1;
	}
	inline ll rs(ll p)
	{
		return p << 1 | 1;
	}
	inline void push_up(ll p)
	{
		t[p].sum = t[ls(p)].sum + t[rs(p)].sum;
	}
	inline void push_down(ll p, ll l, ll r)
	{
		if (t[p].mark == 0) 
			return ;
		ll mid = (l + r) / 2;
		t[ls(p)].sum += t[p].mark * (mid - l + 1);
		t[rs(p)].sum += t[p].mark * (r - mid);
		t[ls(p)].mark += t[p].mark;
		t[rs(p)].mark += t[p].mark;
		t[p].mark = 0;
	}
	//初始化
	void build(ll p = 1, ll l = 1, ll r = n)
	{
		//			t[p].l = l;
		//			t[p].r = r;
		if (l == r)
		{
			t[p].sum = a[l];
			return;
		}
		ll mid = (l + r) / 2;
		build(ls(p), l, mid);
		build(rs(p), mid + 1, r);
		push_up(p);
	}
	//区间修改
	void update(ll tl, ll tr, ll k, ll p = 1, ll l = 1, ll r = n)
	{
		if (l >= tl && r <= tr)
		{
			t[p].sum += k * (r - l + 1);
			t[p].mark += k;
			return ;
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
		return ;
	}
	//区间和查询
	ll query(ll tl, ll tr, ll p = 1, ll l = 1, ll r = n )
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
};
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	segmentTree A(a);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	A.build();
	ll x;
	ll t;
	ll tl, tr, k;
	while (m--)
	{
		cin >> t ;
		switch (t)
		{
			case 1://加上k
			cin >> tl >> tr >> k;
			A.update(tl, tr, k);
			break;
			case 2:	//查询
			cin >> tl >> tr;
			x = A.query(tl, tr) ;
			cout <<	x << "\n";
			break;
		}
	}
	return 0;
}
