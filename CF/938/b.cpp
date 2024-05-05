#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n;
ll arr[N];

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
unordered_map<ll, ll> g;
bool slove()
{
    ll c, d;
    g.clear();
    // memset(arr,0,sizeof (arr));
    n = read();
    c = read();
    d = read();
    // g(i,j)=g(1,1)+(i-1)*c+(j-1)*d
    // 0-n,0-n
    ll minn = 0x3f3f3f3f;
    rep(i, 1, n * n)
    {
        arr[i] = read();
        g[arr[i]]++;
        minn = min(arr[i], minn);
    }
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            if (i == 1 && j == 1)
                continue;
            ll t = minn + (i - 1) * c + (j - 1) * d;
            if (g[t] == 0)
            {
                // cout<<i<<j<<"---";
                // cout << t << "----";
                return false;
            }
            g[t]--;
        }
    }
    return true;
}
int main()
{
#ifdef LOCAL
    freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    t = read();
    // cin >> t;
    while (t--)
    {
        if (slove())
        {
            puts("yes");
            // cout << "yes\n";
        }
        else
        {
            puts("no");
            // cout << "no\n";
        }
    }
    return 0;
}
