#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll a, b, m;
ll f[111][111]; // 长度i,各位数字和%m等于j的个数
void init()
{
	rep(i, 0, 102)
	{
		f[1][i] = 1;
	}
	rep(i, 2, 30)
	{
		rep(j, 0, max((ll)9,m - 1))
		{
			rep(k, 0, 9)
			{
				ll t=(j + k + m) % m;
				if(!t)
					f[i][j] += f[i - 1][t];
			}	
		}
	}
}
ll dfs(ll n)
{
	if (!n)
		return 1;
	ll res = 0;
	vector<ll> nums;
	while (n)
		nums.emplace_back(n % 10), n /= 10;
	ll last = 0; // 数字和
	// 高位往低位
	rrep(i, nums.size() - 1, 0)
	{
		ll x = nums[i];
		// 首位插入[0,x-1]
		rep(j, 0, x - 1)
		{
			rep(k, 0, max((ll)9,m - 1))
			{
				if ((last + j + k) % m == 0)
					res += f[i][k];
			}
		}
		last = (last + x) % m;
		if (!i)
			res++;
	}


	return res;
}
void solve()
{
	cin >> a >> b >> m;
	init();
		// cout << dfs(b) <<"-----"<< dfs(a - 1) << "\n";
	cout << dfs(b) - dfs(a - 1) << "\n";
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
