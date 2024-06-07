#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n=10;
ll gcd(ll a, ll b)
{
	return b > 0 ? gcd(b, a % b) : a;
}
void solve()
{
	cin >> n;
	// cout<<n<<"-";
	ll ans = 0;
	// n * (n + 1) / 2 - 2 + (n - 1) * n;
	ll x=(n/2);
	ll ans1=(n*(n+1)/2%mod-x*(x+1)/2%mod+mod-1)%mod;
	// rep(i, 2, n)
	// {
	// 	if (i & 1)
	// 		ans += i;
	// 	else
	// 		ans += (i >> 1);
	// }
	// cout << ans << "-";
	cout<<ans1<<"\n";
	// n/2
	// a1+2*(n-1)*n/2
	// 2 4 6 8
	// 2 6 10 18
	// 奇数和加偶数和/2
}

int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
	freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
