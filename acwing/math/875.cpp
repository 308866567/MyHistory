#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e9 + 7;


ll qmi(ll a, ll b)//a^b
{
	const ll mod = 998244353 ;
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b = b >> 1;
	}
	return ans % mod;
}
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll n, a, b, p;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> p;
		ll ans = 1;
		//b=1+2+4+...
		while (b > 0)
		{
			if(b&1)
				ans=ans*a%p;
			a=a*a%p;
			b=b>>1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
