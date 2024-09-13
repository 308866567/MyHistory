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
struct node{
    ll t,i;
    bool operator<(node &b){
        return t<b.t;
    }
}a[N];
void solve()
{
    cin>>n;
    rep(i,1,n){
        cin>>a[i].t;
        a[i].i=i;
    }
    sort(a+1,a+1+n);
    ll ans=0;
    rep(i,1,n-1){
        cout<<a[i].i<<" ";
        ans+=(n-i)*a[i].t;
    }
    cout<<a[n].i<<"\n";
    printf("%.2lf\n",1.0*ans/n);
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