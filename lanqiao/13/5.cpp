#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n, ma, mb;
ll a[N], b[N];
ll w[N], c[N];
const ll mod = 1000000007;
void slove()
{
    cin >> n; // 最高进制
    cin >> ma;
    // a>=b
    rep(i, 1, ma)
    {
        cin >> a[i];
    }
    cin >> mb;
    rep(i, 1, mb)
    {
        cin >> b[i];
    }
    w[ma] = 1;
    //11 5 2
    //10 2 1
    rrep(i, ma-1, 0)
    {
        w[i] = w[i + 1] % mod * max((ll)2,min(n, max(a[i+1], b[i+1]) + 1)) % mod;
        w[i] %= mod;
    }
    ll ans = 0;
    rrep(i, ma, 1)
    {
        ans += w[i]%mod * (a[i] - b[i]);
        ans=(ans+mod)%mod;
    }
    cout<<ans;
    return;
}
int main()
{
#ifdef LOCAL
    freopen("/home/xiaobingdu/Downloads/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}
// 快读
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
