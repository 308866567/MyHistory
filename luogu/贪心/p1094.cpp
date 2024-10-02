#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll w,p[N];
void solve()
{
    cin>>w>>n;
    rep(i,1,n){
        cin>>p[i];
    }
    sort(p+1,p+1+n);
    ll ans=0;
    ll l=1,r=n,sum=0;
    while(l<r){
        while(p[l]+p[r]>w){
            // cout<<p[r]<<"\n";
            r--;
            ans++;
        }
        l++,r--,ans++;
        // cout<<p[l]+p[r]<<"\n";
    }
    if(l==r){
        ans++;
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