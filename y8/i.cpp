#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll m;
ll w[2000], v[2000];
ll dp[N];//贡献值i的最小花费
void solve()
{
	cin >> n >> m;
	memset(dp, 0x3f, sizeof dp);
	ll sum = 0;
	ll sw = 0;
	rep(i, 1, n)
	{
		cin >> w[i] >> v[i];
		sum += v[i];
		sw += w[i];
	}
	dp[0] = 0;
	rep(i, 1, n)
	{
//		dp[v[i - 1]] = min(dp[v[i - 1]], w[i - 1]);
		rrep(j, sum + 10, 0)
		{
			if (j - v[i] >= 0)
				dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
		}
	}

	ll minn = 1e18;
	rrep(i, sum + 10, 0)
	{
		minn = min(minn, dp[i]);
		dp[i] = min(minn, dp[i]);
	}

	rep(i, 1, m)
	{
		ll x;
		cin >> x;
		if (x > sw)
		{
			cout << sum << "\n";
			continue;
		}
		ll t = upper_bound(dp, dp + sum + 5, x) - dp;
		//找一个大于=x的
		while (t >= 0 && dp[t] > x)
		{
			t--;
		}


		t = max((ll)0, t);
		t = min(t, sum);
		cout << t << "\n";
	}
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
