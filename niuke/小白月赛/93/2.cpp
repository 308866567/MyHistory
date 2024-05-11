#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
#define mod 998244353
ll n;
string a, b;

ll cal(string &s)
{
	ll ans = 0;
	rep(i, 0, n - 1)
	{
		ans *= 10;
		ans += s[i] - '0';
		ans %= mod;
	}
	return ans;
}
void solve()
{
	cin >> n;
	cin >> a >> b;
	rep(i, 0, n - 1)
	{
		if (a[i] < b[i])
		{
			swap(a[i], b[i]);
		}
	}
	cout << (cal(a) * cal(b)) % mod;
	return;
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
