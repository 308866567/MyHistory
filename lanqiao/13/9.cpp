#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
const ll mod = 1000000007;
ll dp[111][111][111]; // n,m,s
void slove()
{
    ll n, m;
    cin >> n >> m;
    dp[0][0][2] = 1;
    // dp[0][1][1]=1;
    // dp[0][2][0]=1;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            rep(k, 0, 100)
            {
                if(dp[i][j][k]==0) 
                    continue;
                // cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<"\n";
                //下一次遇店
                if (k * 2 <= 104)
                    dp[i + 1][j][k * 2] = (dp[i + 1][j][k * 2] + dp[i][j][k]) % mod;
                //下一次遇花
                if (k - 1 >= 0)
                    dp[i][j + 1][k - 1] = (dp[i][j + 1][k - 1] + dp[i][j][k]) % mod;
            }
        }
    }
    //题目要求了最后一次必须遇花且有酒
    //不可以最后一次0酒遇店
    // cout<<dp[n][m][0]<<' ';
    cout << dp[n][m-1][1];
    return;
}
int main()
{
#ifdef LOCAL
    freopen("/home/xiaobingdu/Downloads/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}
// 快读
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
