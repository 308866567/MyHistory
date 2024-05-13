#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
ll n;
ll arr[N];
void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + n);
	ll maxx = -1;
	ll minn = 0x3f3f3f3f;
	if (n & 1)
	{
		ll t = arr[n];
		maxx = max(t, maxx);
		minn = min(t, minn);
		n--;
	}
	ll l = 1, r = n;
	while (l < r)
	{
		ll t = arr[l] * arr[r];
		l++, r--;
		maxx = max(t, maxx);
		minn = min(t, minn);
	}
	cout << maxx - minn;
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
