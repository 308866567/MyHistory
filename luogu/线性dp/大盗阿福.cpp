#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll w[N];
void solve()
{
    ll f[N];
    // 前i家最大值
    cin >> n;
    rep(i, 1, n)
    {
        cin >> w[i];
    }
    f[0] = 0, f[1] = w[1];
    // 按步思考
    rep(i, 2, n)
    {
        f[i] = max(f[i - 1], f[i - 2] + w[i]);
    }
    cout << f[n] << "\n";
}
void solve2()
{
    ll f[N][2]; // 0表示没偷第i家
    // 按状态思考
    cin >> n;
    rep(i, 1, n)
    {
        cin >> w[i];
    }
    // 按步思考
    f[1][0] = 0, f[1][1] = w[1];
    rep(i, 2, n)
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + w[i];
    }
    cout << max(f[n][0], f[n][1]) << "\n";
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
    cin >> t;
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