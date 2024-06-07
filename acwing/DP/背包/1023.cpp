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
ll arr[10] = {0, 10, 20, 50, 100};
void solve()
{
	cin >> n;
	// 物品4种 10 20 50 100
	// 无限选，完全背包
	// 求方案数
	dp[0] = 1;
	rep(i, 1, 4)
	{
		rep(j, 0, n)
		{
			if (j - arr[i] >= 0)
				dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[n] << "\n";
}
void solve2()
{
	ll m; // 目标金额
	cin >> m;
	ll f[2000][2000];
	rep(i, 1, 4)
	{
		rep(j, 0, m)//从小到大枚举限制
		{
			// 选k个arr[i]
			for (ll k = 0; arr[i] * k <= j; ++k)
			{
				f[i][j] += f[i - 1][j - arr[i] * k];
			}
		}
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
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
