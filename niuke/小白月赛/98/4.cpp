#include <bits/stdc++.h>
#include<map>
using namespace std;
typedef long long ll;
const ll N = 1e4 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
typedef  pair<ll, ll> pii;
ll n;
ll l, r;
char a[N];
ll s1[N];
ll ans = 0;
ll dfs(ll tl, ll tr);
void solve()
{
    cin >> n;
    cin >> l >> r;
    rep(i, 1, n)
    {
        cin >> a[i];
        if (a[i] == '1')
        {
            s1[i]++;
        }
        s1[i] += s1[i - 1];
    }
    dfs(1, n);
    cout << ans << "\n";
}
map<pii, ll> g;
ll dfs(ll tl, ll tr)
{
    if (tl >= tr)
        return 0;
    if (g.count(pii(tl, tr)) != 0)
        return g[pii(tl, tr)];
    ll maxx = 0;
    ll ss0 = 0, ss1 = s1[tr] - s1[tl - 1];
    rep(i, tl, tr)
    {
        if (a[i] == '0')
        {
            ss0++;
        }
        else if (a[i] == '1')
        {
            ss1--;
        }
        if (abs(ss0 - ss1) >= l && abs(ss0 - ss1) <= r)
        {
            ll sum = 0;
            sum += dfs(tl, i);
            sum += dfs(i + 1, tr);
            maxx = max(sum, maxx);
        }
    }
    return maxx;
}

int main()
{
#ifdef LOCAL
    freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
    freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
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
