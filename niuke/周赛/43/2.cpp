#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
vector<ll> nums;
void init()
{
	for (ll i = 0; i * i <= 1e12 + 5; i++)
	{
		nums.emplace_back(i * i);
	}
}
void solve()
{
	cin >> n;
	ll t = lower_bound(nums.begin(), nums.end(), n) - nums.begin();
	ll ans1 = INF, ans2 = INF;
	while (1)
	{
		if (t >= nums.size()) break;
		if (abs(t * t - n) & 1) t++;
		else
		{
			ans1 = (t * t - n) / 2;
			break;
		}
	}
	rrep(i, t-1, 0)
	{
		ll d = abs(n - i * i);
		if (!(d & 1))
		{
			ans2 = d / 2;
			break;
		}
	}
	cout << min(ans1, ans2);
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
	init();
	while (t--)
	{
		solve();
	}
	return 0;
}
