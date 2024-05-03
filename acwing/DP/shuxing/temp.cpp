#include <iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 1;
const ll mod=998244353 ;
ll n, m, a, b;
ll qmi(ll a, ll b)//a^b
{
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b = b >> 1;
	}
	return ans;
}
void slove()
{
	//玩n次
	ll now = 0; //当前i获胜能得到的分数
	double ans = 0;
	ll d = b - a;
	ll ta = 1, td = n - 1;
	ll t = 1;
	ll x = qmi(b, n);
	ll p;
	for (ll i = 1; i <= n; i++)
	{
		//		cout<<qmi(a, ta)<<' '<<qmi(d, td)<<' '<<x<<"\n";
		t = t * (n - i + 1) / i;
		now += qmi(i, m);
		p = t * qmi(a, ta) * qmi(d, td);
		ans =ans+ (1.0*p * now  /x);
		ta++;
		td--;
	}
	cout << ans<< "\n";
	return ;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t=9/4;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> a >> b;
		slove();
	}
	return 0;
}

