#include <iostream>
typedef long long ll;
using namespace std;
const ll N = 3e5 + 5;
ll m, p;//最多有2e5个数
ll n = 0;//当前序列的个数
class BIT//树状数组维护最大值
{
	public:
		ll t[N] = {0}; //存储区间最大值
		//t[i]表示区间[i-low+1,i]的最大值
		ll *a;//数组
		inline lowbit(ll x){
			return x&(-x);
		}
		void build()
		{

		}
		//单点修改
		void update()
		{

		}
		//区间求最大值,单点查询
		ll query()
		{
			return 1;
		}
};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> p;
	char t1;
	ll t2;
	ll a = 0;
	BIT T;
//	T.build(1,1,m);
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		if (t1 == 'A')//添加操作
		{
			t2 = (t2  + a) % p;
			//添加t2到末尾
			n++;
//			T.update(n, n, t2, 1, 1, m);
		}
		else//查询操作
		{
			//			cout<<n-t2+1<<" "<<n<<":";
//			a = T.query(n - t2 + 1, n, 1, 1, m);
			cout << a << "\n";
		}
		//7029
	}
	return 0;
}
