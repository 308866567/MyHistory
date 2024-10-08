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
ll cnt, q[N], s[N];

void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    ll ans = 0;
    q[0] = -2e9;
    rep(i, 1, n)
    {
        ll k = upper_bound(q + 1, q + 1 + cnt, a[i] - 1) - q - 1;
        if (q[k] == a[i] - 1)
        {
            q[k] = a[i], s[k]++;
        }
        else
        {
            q[++cnt] = a[i], s[cnt]++;
        }
    }
    ans = s[1];
    rep(i, 1, cnt)
    {
        ans = min(ans, s[i]);
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