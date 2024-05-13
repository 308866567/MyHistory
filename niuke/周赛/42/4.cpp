#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
ll n;
ll h[N], ne[N], e[N], idx;
unordered_map<ll, ll> g;
unordered_map<ll, ll> f;
struct edge
{
	ll a, b;
} edges[N];

void add(ll a, ll b)
{
	e[++idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
}
ll ans = 0;
ll dfs(ll x, ll p)
{
	f[x] = p;
	g[x];
	for (ll i = h[x]; i != -1; i = ne[i])
	{
		ll y = e[i];
		if (y == p)
		{
			continue;
		}
		if (dfs(y, x) != -1)
			g[x]++;
	}
	// cout<<x<<"--"<<g[x]<<"\n";
	// 断开和父节点的边
	if (x!=1&&g[x] & 1)
	{
		ans++;
		return -1;
	}
	return 0;
}
void solve()
{
	memset(h, -1, sizeof h);
	cin >> n;
	if (n & 1)
	{
		cout << -1 << "\n";
		return;
	}
	rep(i, 1, n - 1)
	{
		ll a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
		edges[i].a = a;
		edges[i].b = b;
	}
	dfs(1, -2);
	if (ans == 0)
	{
		cout << -1;
	}
	else
		cout << ans;
	cout << "\n";
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
