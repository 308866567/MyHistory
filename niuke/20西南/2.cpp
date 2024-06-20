#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
typedef pair<double, double> pii;
unordered_map<double, ll> g;
double cal(pii a)
{
	return a.first / (a.second);
}
void solve()
{
	cin >> n;
	pii t;
	ll ans = 1;
	ll x0 = 0;
	ll y0 = 0;
	ll a0 = 0;
	rep(i, 1, n)
	{
		cin >> t.first >> t.second;
		if (t.first == 0 && t.second == 0)
		{
			a0++;
		}
		else if (t.second == 0)
		{
			y0++;
		}
		else if (t.first == 0)
		{
			x0++;
		}
		else
		{
			double tt = cal(t);
			// cout<<tt<<"\n";
			g[tt]++;
			ans = max(ans, g[tt]);
		}
	}
	ans=max(ans,y0);
	ans=max(ans,x0);
	cout << ans + g[0] << "\n";
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
		solve();
	}
	return 0;
}
