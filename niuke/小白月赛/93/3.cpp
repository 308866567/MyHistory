#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
#define mod 998244353

ll fast_pow(ll a, ll b, ll p)
{
	ll res = 1 % p;
	while (b)
	{
		// cout<<res<<' ';
		if (b & 1)
			res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

ll m, a, b, c;
void solve()
{
	cin >> m >> a >> b >> c;
	ll mmm = m * m % mod * m % mod;
	ll mmod = fast_pow(mmm, mod - 2, mod);
	ll ans = 0;
	if (m == 1)
	{
		ans = c % mod;
	}
	else
	{
		ll cc = m;							   // 3相同
		ll aa = (m * (m - 1) * (m - 2)) % mod; // 0
		ll bb = mmm + mod + mod - aa - cc;	   // 2个
		// cout << bb << "\n";
		ans += cc % mod * c % mod * mmod;
		ans %= mod;
		ans += bb % mod * b % mod * mmod;
		ans %= mod;
		ans += aa % mod * a % mod * mmod % mod;
		ans %= mod;
		// ans=((c+(3*b)%mod)%mod+(m*m-4)%mod*a%mod)%mod;
		// cout<<ans<<"\n";
		// ans*=mm;
		// ans %= mod;
	}
	cout << ans % mod;
	return;
}
int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
