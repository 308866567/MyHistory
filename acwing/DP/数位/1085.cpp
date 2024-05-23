#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll l, r;
ll f[111][111];
void init()
{
	rep(i, 0, 9)
	{
		if (i == 4)
			continue;
		f[1][i] = 1;
	}
	rep(i, 1, 20)
	{
		rep(j, 0, 9)
		{
			if (j == 4)
				continue;
			rep(k, 0, 9)
			{
				if (k == 4)
					continue;
				if (k == 6 && j == 2)
					continue;
				f[i + 1][k] += f[i][j];
			}
		}
	}
}
ll dfs(ll n)
{
	if (!n)
		return 1;
	vector<ll> nums;
	while (n)
		nums.emplace_back(n % 10), n /= 10;

	ll res = 0, last = 0;
	rrep(i, nums.size() - 1, 0)
	{
		ll x = nums[i];
		rep(j, 0, x - 1)
		{
			if (j == 4)
				continue;
			if (last == 6 && j == 2)
				continue;
			res += f[i + 1][j];
		}
		if (last == 6 && x == 2)
			break;
		if (x == 4)
			break;

		last = x;
		if (!i)
			res++;
	}
	
	return res;
}
void solve()
{
	init();
	while (cin >> l >> r)
	{
		if (l + r == 0)
			return;
		// cout << dfs(r) << "-----" << dfs(l - 1) << "\n";
		cout << dfs(r) - dfs(l - 1) << "\n";
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
