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
ll a[N];
ll c[N];
void solve()
{
    cin >> n;
    ll sum = 0;
    ll maxx = 1;
    rep(i, 1, n)
    {
        cin >> a[i];
        if (a[i] > a[maxx])
        {
            maxx = i;
        }
        sum += a[i];
    }
    ll avg = sum / n;
    ll ans = 0;
    rep(i, 1, n)
    {
        c[i]=c[i-1]-avg+a[i];
    }
    sort(c+1,c+1+n);
    ll x1=c[(n+1)/2];
    rep(i,1,n){
        ans+=abs(x1-c[i]);
    }
    cout << ans << "\n";
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