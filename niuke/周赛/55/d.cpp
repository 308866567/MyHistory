#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e3 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
typedef pair<ll, ll> pii;
const ll mod = 1e9 + 7;
ll n;
ll g[N][N];
vector<pii> gt[N][N];
ll dir[10][2] = {1, 0, -1, 0, 0, -1, 0, 1};
bool ff(ll a, ll b)
{
    if (g[a][b] == 0 && a >= 1 && a <= n && b >= 1 && b <= n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
pii cal(ll a, ll b, ll d)
{
    if (dir[d][0] != 0)
    {
        ll t = a;
        while (ff(t- dir[d][0], b))
        {
            t -= dir[d][0];
        }
        return {t, b};
    }
    else
    // if (dir[d][1])
    {
        ll t = b;
        while (ff(a, t- dir[d][1]))
        {
            t -= dir[d][1];
        }
        return {a, t};
    }
}
bool st[N][N];
struct node
{
    pii h;
    ll d;
};

ll bfs()
{
    deque<node> q;
    q.push_back({{1, 1}, 0});
    while (!q.empty())
    {
        node tt = q.front();
        pii h = tt.h;
        q.pop_front();
        if (st[h.first][h.second])
            continue;
        st[h.first][h.second] = 1;
        if (h.first == n && h.second == n)
        {
            return tt.d;
        }
        for (auto it : gt[h.first][h.second])
        {
            q.push_back({it, tt.d + 1});
        }
    }
    return -1;
}
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            cin >> g[i][j];
        }
        g[0][i]=1;
        g[i][0]=1;
        g[n+1][i]=1;
        g[i][n+1]=1;
    }
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            rep(k, 0, 3)
            {
                if (g[i][j] == 1)
                    continue;
                if (ff(i + dir[k][0], j + dir[k][1]))
                {
                    gt[i][j].push_back({i + dir[k][0], j + dir[k][1]});
                }
                if (g[i + dir[k][0]][j + dir[k][1]] == 1)
                {
                    gt[i][j].push_back(cal(i, j, k));
                }
            }
        }
    }
    cout << bfs();
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