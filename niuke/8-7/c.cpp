#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 3e3 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 998244353;
ll n, m;
ll a[N];
ll s[N];
ll c[N][N];
// x个分成y组
ll cal(ll x, ll y)
{
    return c[x + y - 1][y - 1];
}
void init()
{
    rep(i, 0, 2222)
    {
        rep(j, 0, i)
        {
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}
void solve()
{
    init();
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll ans = cal(m, n);
    rep(i, 1, n - 1)
    {
        rep(j, 0, s[i])
        {
            ans = (ans - cal(m - j, n - i) + mod) % mod;
        }
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
