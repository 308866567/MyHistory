#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll x, y;
bool check(ll mid)
{
	ll yy = ceil(1.0 * y / 2);
	if (mid < yy)
	{
		return 0;
	}
	ll sum = yy * 7 + (mid - yy) * 15 - x;
	if (y & 1) sum += 4;
	if (sum >= 0)
		return 1;
	else
		return 0;
}
void solve()
{
	cin >> x >> y;
	ll l = 0, r = x + y + 100, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	if (check(l))
		cout << l;
	else
		cout << l + 1;
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
	while (t--)
	{
		solve();
	}
	return 0;
}
