#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
char s[2000][2000];
void dfs(ll len, ll lx, ll ly)
{
	if (lx > n || ly > n) return ;
	if (len <= 1)
	{
		cout << s[lx][ly];
		return ;
	}
	ll mid = len / 2 ;
	dfs(mid, lx, ly );
	dfs(mid, lx, ly + mid);
	dfs(mid, lx + mid, ly);
	dfs(mid, lx + mid, ly + mid);
	return ;
}
void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		rep(j, 1, n)
		{
			cin >> s[i][j];
		}
		getchar();
	}
	dfs(n, 1, 1);
	cout  << "\n";
}


int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
	freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
