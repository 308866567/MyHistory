#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e3 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n, m, k;
ll cost[N], harm[N];
ll dp[N][N];
void out()
{
	rrep(a, m, 0) // 花费体力
	{
		rrep(b, n, 0) // 花费球
		{
			cout << dp[a][b] << ' ';
		}
		cout << "\n";
	}
	cout << "\n";
}
void solve()
{
	cin >> n >> m >> k;
	rep(i, 1, k)
	{
		cin >> cost[i] >> harm[i];
	}
	// 状态:  剩余体力,收服数量,使用球数
	// 只能1次
	ll C = -1, R = 0x3f3f3f3f;
	rep(i, 1, k)
	{
		// 收服i,体力-,数量+,球数-
		rrep(a, m-1, 0) // 花费体力
		{
			rrep(b, n, 0) // 花费球
			{
				if (a >= harm[i] && b >=cost[i])
				{
					dp[a][b] = max(dp[a][b],
								   dp[a - harm[i]][b - cost[i]] + 1);
				}
				if (dp[a][b] > C)
				{
					C = max(dp[a][b], C);
					R=a;
					// cout << a << " " << b << "\n";
					// cout << C << " " << m - R << "\n----\n";
				}else if(dp[a][b]==C){
					R=min(R,a);
				}
			}
		}
	}
	cout << C << " " << m - R << "\n";
}

int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
	freopen("/home/xiaobingdu/code/c++/out.txt", "w", stdout);
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
