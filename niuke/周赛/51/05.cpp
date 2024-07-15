#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1000 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
typedef pair<ll, ll> pii;
ll n;
ll a[N][N];
ll dir[4][2] = {+1, 0, 0, +1, -1, 0, 0, -1};
bool used[N][N];
ll dfs(ll nx, ll ny, ll maxx, ll s)
{
	if ( used[nx][ny]|| nx > n || ny > n || nx < 1 || ny < 1)
	{
		return 0;
	}
	// cout << nx << "-" << ny << "\n";
	used[nx][ny] = 1;
	if (nx == n && ny == n)
	{
		return 1;
	}
	rep(i, 0, 3)
	{
		ll x = nx + dir[i][0];
		ll y = ny + dir[i][1];
		if (a[x][y] <= maxx)
			if (dfs(x, y, maxx, s + 1))
				return 1;
	}
	return 0;
}
ll amin = 0x3f3f3f3f, amax;
void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		rep(j, 1, n)
		{
			cin >> a[i][j];
			amin = min(amin, a[i][j]);
			amax = max(amax, a[i][j]);
		}
	}
	ll l = a[n][n] - 1, r = amax + 1, mid;
	while (l < r)
	{
		mid = l + r >> 1;
		memset(used, 0, sizeof used);
		if (dfs(1, 1, mid, 0))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
// 		cout << "\n";
	}
	memset(used, 0, sizeof used);
    if (dfs(1, 1, l, 0))
	   	cout << l << "\n";
    else 
        cout<<l-1<<"\n";
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
