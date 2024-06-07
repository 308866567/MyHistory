#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;

ll dp[N];
bool f[N]; // 1表示是
bool cal(ll x)
{
	// vector<ll> num;
	ll sum = 0;
	ll t = x;
	while (x)
	{
		// num.emplace_back(x%10);
		sum += x % 10;
		x /= 10;
	}
	if (sum & 1)
		return 0;
	if (sum < t)
		if (!f[sum])
			return 0;
	return 1;
}

void solve()
{
	cin >> n;
	ll ans = 0;
	rep(i, 1, n)
	{
		if (cal(i))
		{
			f[i]=1;
			ans++;
			cout << i << "-";
		}
	}
	cout << ans << "\n";
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
