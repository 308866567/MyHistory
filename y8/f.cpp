#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll dp[N][3];
ll a, b;
bool f[N];//0表示2
ll w[N];
void solve()
{
	cin >> n;
	cin >> a >> b;
	ll sum = 0;
	rep(i, 1, n)
	{
		cin >> w[i];
		sum += w[i];
	}
	ll t;
	rep(i, 1, n)
	{
		cin >> t;
		if (t == 1) f[i] = 1;
		else f[i] = 0;
	}
//	cout << sum << "\n";
	rep(i, 1, n)
	{
		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		dp[i][1] = max(dp[i][1], dp[i - 1][1]);
		dp[i][2] = max(dp[i][2], dp[i - 1][2]);
		if (i - a >= 0)
			dp[i][0] = max(dp[i][0], dp[i - a][1]);
		if (i - b >= 0)
			dp[i][0] = max(dp[i][0], dp[i - b][2]);

		if (f[i] == 1)
		{
			if (i - a >= 0)
				dp[i][1] = max(dp[i][1], dp[i - a][1] + w[i]);

			dp[i][1] = max(dp[i][1], dp[i - 1][0] + w[i]);
			dp[i][1] = max(dp[i][1], dp[i - 1][2] + w[i]);

		}
		else
		{
			if (i - b >= 0)
				dp[i][2] = max(dp[i][2], dp[i - b][2] + w[i]);

			dp[i][2] = max(dp[i][2], dp[i - 1][0] + w[i]);
			dp[i][2] = max(dp[i][2], dp[i - 1][1] + w[i]);
		}

	}

//	rep(i, 0, 2)
//	cout << dp[n][i] << " ";
//	cout << "\n";
	cout << max(dp[n][0], max( dp[n][1], dp[n][2] )) << "\n";
}

int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
	freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
