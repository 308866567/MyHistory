#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n, k;
ll arr[N];
ll v[N];
bool f(ll l, ll r)
{
	rep(i, 1, k)
	{
		if (v[i] != 1) return 0;
	}
	return 1;
}
void solve()
{
	cin >> n >> k;
	rep(i, 1, n)
	{
		cin >> arr[i];
	}
	ll l = 1, r = k;
	rep(i, 1, k)
	{
		v[arr[i]]++;
	}
	ll ans = 0;
	while (r <= n)
	{
		if (f(l, r)) 
			ans++;
		v[arr[l]]--;
		l++;
		r++;
		v[arr[r]]++;
	}
	cout << ans << "\n";
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
