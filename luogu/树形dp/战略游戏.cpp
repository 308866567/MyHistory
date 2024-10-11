#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1600;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
vector<ll> a[N];
ll f[N][2]; // 覆盖这棵子树所需的最少士兵数目,1表示u节点有士兵,0表示没有
bool ut[N];
void dfs(ll u)
{
    if (ut[u])
        return;
    // cout << u << " ";
    ut[u] = 1;
    // f[u][1]=sum(f[s][0]),sum(f[s][1])
    // f[u][0]=sum(f[s][1])
    f[u][1] = 1;
    rep(i, 0, a[u].size() - 1)
    {
        ll s = a[u][i];
        if (!ut[s])
        {
            dfs(s);
            f[u][0] += f[s][1];
            f[u][1] += min(f[s][1], f[s][0]);
        }
    }
}
void solve()
{
    cin >> n;
    ll root;
    rep(i, 1, n)
    {
        ll t, len;
        cin >> t >> len;
        if (len == 0)
            root = t;
        rep(j, 1, len)
        {
            ll s = 0;
            cin >> s;
            a[t].emplace_back(s);
            a[s].emplace_back(t);
        }
    }
    dfs(root);
    cout << min(f[root][0], f[root][1]);
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