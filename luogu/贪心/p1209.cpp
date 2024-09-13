#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll m,s,c;
ll a[N];
ll d[N];

void solve()
{
    cin>>m>>s>>c;
    rep(i,1,c){
        cin>>a[i];
    }
    sort(a+1,a+1+c);
    ll ans=c;
    rep(i,2,c){
        d[i-1]=a[i]-a[i-1]-1;
    }
    sort(d+1,d+c);
    if(m<c){
        rep(i,1,c-m){
            ans+=d[i];
        }
    }
    cout<<ans<<"\n";
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