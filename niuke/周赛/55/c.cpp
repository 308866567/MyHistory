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
ll ans[N];
// 最多一个0
void solve()
{
    ll s0 = 0;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
        if (a[i] == 0)
            s0++;
    }
    if (s0 > 1)
    {
        cout << "NO\n";
        return;
    }
    sort(a + 1, a + 1 + n);
    ll t = 1;
    ans[1] = a[1];
    a[1] = -1;
    a[0] = -1;
    for (ll i = 3; i <= n; i += 2)
    {
        t=1;
        while (t <= n && a[t] <= ans[i - 2])
        {
            t++;
        }
        ans[i] = a[t];
        a[t] = -1;
    }
    t = 1;
    for (ll i = 2; i <= n; i += 2)
    {
        t=1;
        while (t <= n && a[t] <= ans[i - 2])
        {
            t++;
        }
        ans[i] = a[t];
        a[t] = -1;
    }
    rep(i, 2, n-1)
    {
        if (!(ans[i-1]*ans[i]<ans[i]*ans[i+1]))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    rep(i, 1, n)
    {
        cout << ans[i] << " ";
    }
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