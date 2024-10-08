#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 13;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll f[20][20];
void init()
{
	
}

ll dfs(ll n)
{
	if (n == 0)
		return 0;
	vector<ll> nums;
	while (n)
		nums.emplace_back(n % 10), n /= 10;
	ll res = 0;
	ll last = 9999;
	rrep(i, nums.size() - 1, 0)
	{
		ll x = nums[i];
		rep(j, (i == (nums.size() - 1)), x-1)
		{
			if (abs(last - j) >= 2)
				res += f[i+1][j];//i是数组下标,会小1
		}
		if (abs(x - last) >= 2)
			last = x;
		else
			break;
		if (!i)
			res++;
	}
	rep(i, 1, nums.size() - 1)
	{
		rep(j, 1, 9)
		{
			res += f[i][j];
		}
	}
	return res;
}
void solve()
{
	init();
	ll l, r;
	cin >> l >> r;
	cout<<dfs(20);
	// cout << dfs(r) << "---" << dfs(l - 1) << "\n";
	cout << dfs(r) - dfs(l - 1) << "\n";
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
