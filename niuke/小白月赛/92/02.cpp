#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n, h;
char g[10][N];
void solve()
{
	cin >> n >> h;
	rep(i, 1, 5)
	{
		rep(j, 1, n)
		{
			cin >> g[i][j];
		}
	}
	ll ans = 0;
	rep(i, 1, n)
	{
		if (h >= 1 && g[2][i] == '*')
		{
			ans++;
			h--;
			if (h >= 1 && g[1][i] == '*')
			{
				ans++;
				h--;
			}
		}
		//
		if (h >= 1 && g[4][i] == '*')
		{
			ans++;
			h--;
			if (h >= 1 && g[5][i] == '*')
			{
				ans++;
				h--;
			}
		}
	}
	
	rep(i, 1, n)
	{
		if (h >= 2 && g[2][i] != '*' && g[1][i] == '*')
		{
			ans++;
			h -= 2;
		}
		//
		if (h >= 2 && g[4][i] != '*' && g[5][i] == '*')
		{
			ans++;
			h -= 2;
		}
	}

	cout << ans;
	return;
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
// 快读
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
