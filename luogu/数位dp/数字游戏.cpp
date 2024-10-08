#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 13;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll f[20][20]; // 长度,首位
void init()
{
    f[1][0]=0;
    rep(i, 0, 10)
    {
        rep(j, 1, 10)
        {
            
        }
    }
}
// 求区间内的不降数
ll dfs(ll n)
{
    if (n == 0)
        return 0;
    vector<ll> nums;
    while (n)
        nums.emplace_back(n % 10), n /= 10;
    ll res = 0;
    ll last = -1;
    rrep(i, nums.size() - 1, 1)
    {
        ll x = nums[i];
        if (x < last)
            break;
        // 填<nums[i]
        rep(j, last, 9)
        {
            // 不降数
            res += f[i - 1][9];
        }
        // 填nums[i]
        if (i == 0)
            res++;
        last = x;
    }
    return res;
}
void solve()
{
    init();
    ll l, r;
    cin >> l >> r;
    // cout << dfs(r) << "---" << dfs(l - 1) << "\n";
    cout << dfs(r) - dfs(l - 1) << "\n";
}

int main()
{
#ifdef LOCAL
    freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
