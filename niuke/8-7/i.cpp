#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n, x,y;
ll h[N],ne[N],e[N],idx;
void add(ll a,ll b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
ll ans=1;
ll sum=0;
void dfs(ll now){
    if(n==y)
        return ;
    for(ll i=h[now];~i;i=ne[i]){
        ll j=e[i];
        if(j!=y){
            sum++;
            dfs(j);
        }
    }
}
void solve()
{
    memset(h,-1,sizeof h);
    cin>>n>>x>>y;
    rep(i,1,n-1){
        ll ta,tb;
        cin>>ta>>tb;
        add(ta,tb);
        add(tb,ta);
    }
    dfs(x);
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
