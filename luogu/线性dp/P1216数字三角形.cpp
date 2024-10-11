#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e3 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll a[N][N];
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        rep(j, 1, i)
        {
            cin >> a[i][j];
        }
    }
}
// 顺推法
ll b[N][N];
ll p[N][N];
// 顺推法输出路径
void out(ll x, ll y)
{

    if (x > 1)
    {
        out(x - 1, y - p[x][y]);
    }
    cout << a[x][y] << " ";
}
void solve1()
{
    ll ddb[N*10][N];
    rep(i, 1, n)
    {
        rep(j, 1, i)
        {
            b[i][j] = a[i][j];
        }
    }
    rep(i, 2, n)
    {
        rep(j, 1, i)
        {
            // b[i][j] +=max(b[i-1][j],b[i-1][j-1]);
            if (b[i - 1][j] > b[i - 1][j - 1])
            {
                b[i][j] += b[i - 1][j];
                p[i][j] = 0;
            }
            else
            {
                b[i][j] += b[i - 1][j - 1];
                p[i][j] = 1;
            }
        }
    }
    ll ans = 0;
    rep(i, 1, n)
    {
        if (b[n][i] > b[n][ans])
            ans = i;
    }
    // out(n,ans);
    cout << b[n][ans] << "\n";
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
        solve1();
    }
    return 0;
}