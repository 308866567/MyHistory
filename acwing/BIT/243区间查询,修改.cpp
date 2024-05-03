#include <iostream>
using namespace std;

class BIT3
{
	public:
		typedef long long ll;
		const static ll N = 1e2 + 1;
		ll n, m;
		ll a[N] = {0}; //原数组
		ll td[N] = {0}; //a的差分数组
		//a[i]=d1+d2+..+dia 
		ll tdi[N] = {0}; //差分数组*i
		//因为区间和s[x]=(x+1)*(d1+..dx)-(x*dx+...+1*d1) 
		void build(){
			//o(n)构建树状数组
			//树状数组t[i]的值为原数组前缀和s[i]-s[i-lowbit[i]]
			//即a[i-lowbit[i]+1,i]的区间和=s[i]-s[i-lowbit[i]]
			//差分数组的s[i]=a[i]
			for (int i = 1; i <= n; i++)
			{
				//子节点初始值为原数组
				//td为原数组的差分数组
				//树状数组底层td[i]=a[i]-a[i-1]
				ll j = a[i] - a[i - 1];//差分值 
				td[i] += j;
				tdi[i] += j * i;
				//利用子节点更新父节点
				j = i + lowbit(i);
				if (j <= n)
				{
					//+=是因为一个父节点会有多个子节点
					td[j] += td[i]; 
					tdi[j] += tdi[i];
				}
			}
		}
		void slove()
		{
			cin >> n >> m;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
				//暴力建树
//				update(i, a[i] - a[i - 1], td);
//				update(i, (a[i] - a[i - 1])*i, tdi);
			}
			build();
			char a;
			ll l, r, d;
			while (m--)
			{
				cin >> a;
				if (a == 'Q')//区间查询
				{
					cin >> l >> r;
					ll d = (sum(r) - sum(l - 1));
					cout << d << "\n";
				}
				else//区间修改
				{
					cin >> l >> r >> d;
					add(l, r, d);
				}
			}
		}
		inline ll lowbit(ll x)
		{
			return x & (-x);
		}
		//单点更新差分数组
		void update(ll x, ll k, ll *t)
		{
			for (int i = x; i <= n; i += lowbit(i))
			{
				t[i] += k;
			}
		}
		//返回a[x],单点查询
		ll query(ll x, ll *t)
		{
			ll res = 0;
			for (int i = x; i > 0; i -= lowbit(i))
			{
				res += t[i];
			}
			return res;
		}
		//区间修改
		void add(ll l, ll r, ll d)
		{
			update(l, d, td);
			update(r + 1, -d, td);
			update(l, l * d, tdi);
			update(r + 1, (r + 1) * -d, tdi);
		}
		//查询原数组a[1,i]的前缀和
		ll sum(ll x)
		{
			//s[x]=(x+1)*(d1+..dx)-(x*dx+...+1*d1)
			return  query(x, td) * (x + 1) - query(x, tdi) ;
		}
};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	BIT3 A;
	A.slove();
	return 0;
}
