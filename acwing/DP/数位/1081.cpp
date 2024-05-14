#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll x, y, k, b;
// 组合数
ll f[55][55]; // i个里选j个
void init()
{
	rep(i, 0, 50)
	{
		rep(j, 0, i)
		{
			if (j == 0)
				f[i][j] = 1;
			// 不选第i个和选第i个
			else
				f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
		}
	}
}

ll dfs(ll n)
{
	if (n==0)
	{
		return 0;
	}
	vector<ll> nums; // 从低位到高位
	// n转换成b进制
	while (n)
	{
		nums.emplace_back(n % b);
		n /= b;
	}
	// 满足条件b进制的数的特点是有k个1,其他位都是0,小于nums
	ll last = 0; // 当前分支上已经有了几个1
	ll res = 0;
	// 从高位开始尝试拼凑
	for (ll i = nums.size() - 1; i >= 0; i--)
	{
		ll x = nums[i];
		if (x)
		{
			// 当前位可填[0,x-1],选择填0,其他数都是不符合要求的
			// 高位已经小于n其他位可以随便填了
			// c(i,k-之前填的1的个数)
			// 左分支,只填0
			res += f[i][k - last];
			// 当前位尝试填1,更新last,进入下一重循环,该分支已经统计完了
			if (x > 1)
			{
				if (k - last - 1>= 0)
					res += f[i][k - last - 1];
				break;
			}
			// 右分支,当前位填x
			else if(x==1)
			{
				last++;
				if (last > k)
					break;
			}
		}
		// x只能填0时
		// 最右侧分支,即=n时
		if (i==0 && last == k)
			res++;
	}
	return res;
}
void solve()
{
	cin >> x >> y >> k >> b;
	init();
	cout << dfs(y) - dfs(x - 1);
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
