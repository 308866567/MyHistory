#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n, k;
ll ship[N];//耐久度


void solve3()
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
void solve()
{
    cin >> n >> k;
    rep(i, 1, n)
    {
        cin >> ship[i];
    }
    ll l = 1, r = n;//左右指针
    ll ans = 0;
    //TODO
    for (int i = 0 ; i < k; i++)
    {
        if (l > r)
            break;
        if(!(i&1)){
            ship[l]-=1;
            if(ship[l]==0){
                l++;
                ans++;
                continue;
            }
        }else{
            ship[r]-=1;
            if(ship[r]==0){
                r--;
                ans++;
                continue;
            }
        }
    }
    cout << ans << "\n";
    return;
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
        solve();
    }
    return 0;
}

