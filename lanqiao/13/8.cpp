#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
bool g[111][111];
ll ans[111][111];
ll dir[9][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
void f(ll i, ll j)
{
    rep(x, 0, 7)
    {
        ans[i + dir[x][0]][j + dir[x][1]]++;
    }
}
void slove()
{
    ll n, m;
    cin >> n >> m;
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            cin >> g[i][j];
            if (g[i][j])
                f(i, j);
        }
    }
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            if (!g[i][j])
                cout << ans[i][j] << " ";
            else
                cout << 9 << " ";
        }
        cout << "\n";
    }
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
