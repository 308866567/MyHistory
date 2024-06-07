#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll arr[N];
unordered_map<ll, vector<ll>> g;
//传入终点
bool f(ll a, ll b)
{
	ll sum = 0;
	rep(i, 0, 2)
	{
		if (arr[a - i] != arr[b - i])
			sum++;
	}
	if (sum != 1)
		return 0;
	else
		return 1;
}
void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		cin >> arr[i];
		g[arr[i]];
		g[arr[i]].emplace_back(i);
	}
	ll ans = 0;
	ll ans2 = 0;
	rep(i, 3, n)
	{
		rep(j, i + 1, n)
		{
			if (f(i, j))
			{
				ans++;
				//	cout << i << "---" << j << "---  ";
			}

		}
	}
	
	rrep(i, n - 2, 3)
	{
		rep(j, 0, g[arr[i]].size() - 1)
		{
			ll it = g[arr[i]][j];
			if (it < 3) continue ;
			if (f(i, it))
			{
//				cout << i << "---" << it << "---  ";
				ans2++;
			}
//			if (f(i + 1, it + 1))
//			{
//				ans2++;
////				cout << i << "---" << it << "---  ";
//			}
//			if (f(i + 2, it + 2))
//			{
//				ans2++;
//				//	cout << i << "---" << it << "---  ";
//			}
		}
		g[arr[i]].pop_back();
	}
	cout << ans << "--" << ans2;
	cout << "\n";
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
	cin >> t;
//	t = 3;
	while (t--)
	{
		solve();
	}
	return 0;
}
