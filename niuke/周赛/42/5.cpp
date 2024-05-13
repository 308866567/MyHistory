#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n, k;
unordered_map<ll, ll> g;
void solve()
{
	cin >> n >> k;
	string s;
	cin >> s;
	ll ans = 0;
	rep(i, 0, n - 1)
	{
		ll j = s[i] - '0';
		g[j]++;
		ans += j;
	}
	if (k == 1)
	{
		cout << ans % mod << "\n";
	}
}
int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
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
