// https://www.acwing.com/file_system/file/content/whole/index/content/4184002/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll k;
ll w[N];
void solve()
{
    ll f[N][120][2];
    cin >> n >> k;
    rep(i, 1, n)
    {
        cin >> w[i];
    }
    // 初始化
    memset(f,0,sizeof f);
    rep(i, 0, k)
    {
        f[0][i][1] = -1e6;
    }
    rep(i, 1, n)
    {
        rep(j, 1, k)
        {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
        }
    }
    cout << f[n][k][0] << "\n";
}
void solve2()
{
    ll f[120][2];
    cin >> n >> k;
    rep(i, 1, n)
    {
        cin >> w[i];
    }
    // 初始化
    memset(f,0,sizeof f);
    rep(i, 0, k)
    {
        f[i][1] = -1e6;
    }
    rep(i, 1, n)
    {
        rep(j, 1, k)
        {
            f[j][0] = max(f[j][0], f[j][1] + w[i]);
            f[j][1] = max(f[j][1], f[j - 1][0] - w[i]);
        }
    }
    cout << f[k][0] << "\n";
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
        solve2();
    }
    return 0;
}

//  "-Wl,--stack=134217728",
// ulimit -s 134217728
#include <sys/resource.h>
void add()
{
    const rlim_t kStackSize = 64 * 1024 * 1024; // min stack size = 16 MB
    struct rlimit rl;
    int result;
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
}