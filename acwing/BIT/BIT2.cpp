
#include<iostream>
using namespace std;

typedef long long ll;
static const ll N = 1e2 + 5; //���鳤��
ll arr[N] = {0};
ll n, m;
//ģ�幹��
class BIT
{
	public:
		ll *A;
		ll t[N + 2] = {0};

		BIT(ll* arr)
		{
			A = arr;
		}
		inline ll lowbit(ll x)
		{
			return x & (-x);
		}

		//ʹ�õ����޸Ĺ�����״����
		void build(ll *arr, ll len)
		{
			A = arr;
			//�±��1��ʼ
			for (int i = 1; i <= len; i++)
			{
				update(i, A[i]);
			}
		}
		//�������,��i��ʼ���µ�N
		void update(ll i, ll k)
		{
			for (; i <= N; i += lowbit(i))
			{
				t[i] += k; 
			}
		}

		//[1,i]ǰ׺�Ͳ�ѯ
		ll query(ll i)
		{
			ll res = 0;
			for (; i > 0; i -= lowbit(i))
			{
				res += t[i];
			}
			return res;
		}



		//��չ
		//�����޸�,����ʱupdate(i,a[i]-a[i-1]);
		void update(ll l, ll r, ll k)
		{
			update(l, k);
			update(r+1, -k);
		}
		//�����ѯ
		//[tl,tr]=[1,tr]-[1,tl-1]
		ll query(ll tl, ll tr)
		{
			return query(tr) - query(tl - 1);
		}
		void out()
		{
			for (int i = 1; i <= n+8; i++)
			{
				cout<<t[i]<<" ";
			}
			cout<<"\n";
			ll x;
			for (int i = 1; i <= n+8; i++)
			{
				x = query(i, i);
				cout << x << " ";
			}
			cout << "\n��:";
			x = query(1, n);
			cout  << x << "\n";
		}

};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	BIT A(arr);
	A.build(arr, n);
	ll t;
	ll tl, tr, k;
	ll x;
	A.out();
	while (m--)
	{
		cin >> t ;
		switch (t)
		{
			case 1://����k
				cin >> tl >> tr >> k;
				A.update(tl, tr, k);
				break;
			case 2:	//��ѯ
				cin >> tl >> tr;
				x = A.query(tl, tr);
				cout  << x << "\n";
				break;
		}
		A.out();
	}
	return 0;
}

