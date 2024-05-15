#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll a, b;
ll f[100][15]; // 长度为i,首位为j的方案数
void init()
{
	// f[1][j]=1
	rep(j, 0, 9)
	{
		f[1][j] = 1;
	}
	rep(i, 1, 90)
	{
		rep(j, 0, 9)
		{
			rep(k, j, 9)
			{
				f[i + 1][j] += f[i][k];
			}
		}
	}
}
ll dfs(ll n)
{
	if (n == 0)
		return 1;
	ll res = 0;
	vector<ll> nums;
	while (n)
	{
		nums.emplace_back(n % 10);
		n /= 10;
	}
	// 不含前导0
	// 高位向低位
	ll last = 0;
	rrep(i, nums.size() - 1, 0)
	{
		ll x = nums[i];
		if (x < last)
			break;
		// 当前位填[0,x-1],要大于前一位
		rep(j, last, x - 1)
		{
			res += f[i + 1][j];
		}
		// 填x
		// 最右分支
		if (i == 0)
			res++;
		last = x;
	}
	return res;
}
void solve()
{
		init();
	while (cin >> a >> b)
	{
		// cout<<dfs(b)<<"  "<<dfs(a-1)<<"----";
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
