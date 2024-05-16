#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll f[30][11];
void init()
{
	rep(i, 1, 9)
	{
		f[1][i] = 1;
	}
	rep(i, 2, 30)
	{
		rep(j, 0, 9)
		{
			rep(k, 0, 9)
			{
				// 不含前导0的方案数
				if (abs(j - k) >= 2)
					f[i][j] += f[i - 1][k];
			}
		}
	}
}

ll n;
ll l, r;
ll dfs(ll n)
{
	if (n == 0)
	{
		return 0;
	}
	ll res = 0;
	vector<ll> nums;
	while (n)
	{
		nums.emplace_back(n % 10);
		n /= 10;
	}
	// 找相邻两数之差为1的数
	ll last = -1;
	rrep(i, nums.size() - 1, 0)
	{
		ll x = nums[i];
		ll j = 0;
		if (i == nums.size() - 1)
			j++;
		for (; j < x; j++)
		{
			if (abs(j - last) >= 2)
				res += f[i + 1][j];
		}
		// x
		if (abs(x - last) >= 2)
			last = x;
		if (!i)
			res++;
	}
}
void solve()
{
	cin >> l >> r;
	init();
	cout << dfs(r) - dfs(l - 1);
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
		init();
		solve();
	}
	return 0;
}
