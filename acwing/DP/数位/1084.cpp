#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll a, b, m;
ll f[111][11][111]; // 长度i,首位为j,各位数字和%m等于k的个数
void init()
{
	memset(f, 0, sizeof f);
	rep(i, 0, 9)
	{
		f[1][i][i % m]++;
	}
	rep(i, 1, 30)
	{
		rep(j, 0, 9) // 首位
		{
			rep(k, 0, m - 1)
			{
				// 当前为f[i][j][k]
				//  第i位填t
				rep(t, 0, 9)
				{
					f[i + 1][t][(t + k + m) % m] += f[i][j][k];
				}
			}
		}
	}
	// for (int i = 2; i < 20; i++)
	// 	for (int j = 0; j <= 9; j++)
	// 		for (int k = 0; k < m; k++)
	// 			for (int x = 0; x <= 9; x++)
	// 				f[i][j][k] += f[i - 1][x][(k - j+m)%m];
}
ll dfs(ll n)
{
	if (!n)
		return 1;
	vector<ll> nums;
	while (n)
		nums.emplace_back(n % 10), n /= 10;
	ll res = 0;
	ll last = 0; // 数字和
	// 高位往低位
	rrep(i, nums.size() - 1, 0)
	{
		ll x = nums[i];
		// 当前位插入[0,x-1]
		rep(j, 0, x - 1)
		{
			rep(k, 0, m - 1)
			{
				//不含j是因为，f数组已经算过j的值了
				if ((last + k + m) % m == 0)
					res += f[i + 1][j][k];
			}
		}
		// for (int j = 0; j < x; j++)				// 第i位放0~x-1
		// 	res += f[i + 1][j][(m - last) % m]; // 0~i位，所以一共有i+1位

		last += x;
		if (!i && last % m == 0)
			res++;
	}
	return res;
}
void solve()
{
	while (cin >> a >> b >> m)
	{
		init();
		// cout << dfs(b) << "-----" << dfs(a - 1) << "\n";
		cout << dfs(b) - dfs(a - 1) << "\n";
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
