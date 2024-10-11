#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 302;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n,m;
ll b[N];
ll a[N][N];
ll w[N];
ll f[N][N];
ll v[N];
int dfs(ll u){
    rep(i,v[u],m){
        f[u][i]=w[u];
    }
    rep(i,0,b[u]-1){
        ll s=a[u][i];
        dfs(s);
        rrep(j,m,v[u]){
            rep(k,0,j-v[u]){
                f[u][j]=max(f[u][j],f[u][j-k]+f[s][k]);
            }
        }
    }
    return 0;
}
void solve()
{
    cin>>n>>m;
    rep(i,1,n){
        ll p;
        cin>>p>>w[i];
        a[p][b[p]++]=i;
        v[i]=1;
    }
    v[0]=0;
    dfs(0);
    cout<<f[0][m];
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