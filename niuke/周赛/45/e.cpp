#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll h[N],e[N],ne[N],idx;
void add(ll a,ll b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(ll now,ll f1,ll f2){



}
void solve()
{
	cin >> n;
	rep(i,1,n){
		ll a,b;
		cin>>a>>b;
		add(a,b);
	}
	dfs(1,0,0);
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
