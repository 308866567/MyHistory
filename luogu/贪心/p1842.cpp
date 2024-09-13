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
struct node
{
    ll w=0, s=0;
    bool operator<(const node t)
    {
        return w + s < t.w + t.s;
    }
} a[N];
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i].w >> a[i].s;
    }
    sort(a + 1, a + 1 + n);
    ll ans = -2e9;
    ll sum = 0;
    rep(i, 1, n)
    {
        sum += a[i - 1].w;
        ans = max((ll)ans,sum - a[i].s);
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