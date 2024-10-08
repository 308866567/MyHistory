#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n, m;
ll a[N];
map<ll, ll> g;
void solve()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a[i];
        g[a[i]]++;
    }
    ll ans = 0;
    ll last_num = g[1];
    ll last_level = 0;
    for (auto it : g)
    {
        // cout<<it.first<<" "<<it.second<<"\n";
        if (it.second>0&&it.first == last_level + 1)
        {
            last_num = min(it.second, last_num);
            ans += last_num;
            last_level++;
            // cout<<ans<<"\n";
        }
        else
        {
            break;
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
