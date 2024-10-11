#include <bits/stdc++.h>
#include <iostream>
// https://www.luogu.com.cn/problem/P1352
using namespace std;
typedef long long ll;
const ll N = 6e3 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll r[N];
vector<ll> a[N];
ll f[N][2];//0表示u不来,1表示u来
void dfs(ll u)
{
	//f[u][1]=sum(f[s][0])
	//f[u][0]=sum(f[s][1]),sum(f[s][0])
	f[u][1]=r[u];
	if(!a[u].empty())
	rep(i, 0, a[u].size() - 1)
	{
		ll s = a[u][i];
		dfs(s);
		f[u][1]+=f[s][0];
		f[u][0]+=max(f[s][1],f[s][0]);
	}
}
bool st[N];
void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		cin >> r[i];
	}
	rep(i, 1, n-1)
	{
		ll s, p;
		cin >> s >> p;
		a[p].push_back(s);
		st[s] = 1;
	}
	ll root = 1;
	rep(i, 1, n)
	{
		if (!st[i])
		{
			root = i;
			break;
		}
	}
	dfs(root);
	cout<<max(f[root][0],f[root][1]);
}

int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
	freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
	// ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}