#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll arr[10];
void solve()
{
	rep(i, 1, 5)
	{
		cin >> arr[i];
	}
	ll t = arr[1];
	sort(arr + 1, arr + 1 + 5);
	ll ans = 0;
	rrep(i, 4, 1)
	{
		if (arr[i] == t)
		{
			ans = 5 - i;
			break;
		}

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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
