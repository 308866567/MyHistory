#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll V;
ll v[N], w[N], s[N];
ll dp[N];
// 朴素做法 o(n si)
void solve()
{
	cin >> n >> V;
	rep(i, 1, n)
	{
		cin >> v[i] >> w[i] >> s[i];
	}
	rep(i, 1, n)
	{
		rrep(j, V, 0)
		{
			for (ll k = 1; k <= s[i]; k++)
			{
				if (j >= k * v[i])
					dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
			}
		}
	}
	cout << dp[V] << "\n";
}
// 二进制优化 o(m logsi)
// 拆分物品数量s
ll vv[N], ww[N], num = 1;
void solve1()
{
	cin >> n >> V;
	rep(i, 1, n)
	{
		cin >> v[i] >> w[i] >> s[i];
		ll ss = s[i];
		for (ll j = 1; j <= ss; j <<= 1)
		{
			vv[num] = j * v[i];
			ww[num++] = ss * w[i];
			ss -= j;
		}
		if (ss)
		{
			vv[num] = ss * v[i];
			ww[num++] = ss * w[i];
		}
	}
	// 01背包处理即可
	rep(i, 1, n)
	{
		rrep(j, V, 0)
		{
			if (j - vv[i] >= 0)
				dp[j] = max(dp[j], dp[j - vv[i]] + ww[i]);
		}
	}
	cout << dp[V] << "\n";
}
// 单调队列优化 o(mn)
// 拆分背包容量m,根据v的余数分类
ll g[N];
ll f[N];
ll q[N];
void solve2()
{
	cin >> n >> V;
	rep(i, 1, n)
	{
		cin >> v[i] >> w[i] >> s[i];
	}
	rep(i, 1, n)
	{
		memcpy(g, f, sizeof(f));
		rep(j, 0, v[i] - 1) // 拆分容量为v[i]个类,j表示余数
		{
			ll h = 0, t = -1;
			for (ll k = j; k <= V; k += v[i]) // 单调队列更新
			{
				// 维护窗口[k-s[i]*v[i],k]
				// 弹出过期的值,下标在窗口的左边
				if (h <= t && q[h] < k - s[i] * v[i])
					h++;
				// q[h]表示队头,代表最大的g的下标
				//(k - q[h]) / v[i]表示还能放入物品的个数
				if (h <= t)
					f[k] = max(g[k],
							   g[q[h]] + (k - q[h]) / v[i] * w[i]);
				// 队列插入f[k],队尾弹出比f[k]小的值
				// g[k]和g[q[t]]比较
				// 窗口只在g数组上滑动
				while (h <= t && g[k] >= g[q[t]] + (k - q[t]) / v[i] * w[i])
					t--;
				q[++t] = k;
			}
		}
	}
	cout << f[V] << "\n";
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
		solve2();
	}
	return 0;
}
