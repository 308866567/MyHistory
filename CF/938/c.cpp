#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n, k;
ll ship[N];
ll ls[N], rs[N];
void solve()
{
    cin >> n >> k;
    rep(i, 1, n)
    {
        cin >> ship[i];
    }
    ll l = 1, r = n;
    ll ans = 0;
    rep(i, 1, k)
    {
        if (l > r)
            break;
        // 奇数
        if (i & 1)
        {
            ship[l]--;
            if (ship[l] == 0)
            {
                ans++;
                l++;
            }
        }
        else
        {
            ship[r]--;
            if (ship[r] == 0)
            {
                ans++;
                r--;
            }
        }
    }
    cout << ans << "\n";
    return;
}

ll solve2()
{
    cin >> n >> k;
    ll sum = 0;

    rep(i, 1, n)
    {
        cin >> ship[i];
        ls[i] = ship[i] + ls[i - 1];
        sum += ship[i];
    }
    ll j = 1;
    rrep(i, n, 1)
    {
        rs[j] = ship[i] + rs[j - 1];
        j++;
    }
    if (k >= sum)
    {
        return n;
    }
    ll l, r;
    ll ans = 0;
    if (k & 1)
    {
        l = (k / 2 )+ 1;
        r = k / 2;
    }
    else
    {
        l = r = k / 2;
    }
    

    ans += upper_bound(ls + 1, ls + 1 + n, l) - ls-1;
    ans += upper_bound(rs + 1, rs + 1 + n, r) - rs-1;
    return max((ll)0,ans);
}
int main()
{
#ifdef LOCAL
    freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        // slove();
        cout << solve2() << "\n";
    }
    return 0;
}
