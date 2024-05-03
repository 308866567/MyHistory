#include <bits/stdc++.h>
using namespace std;
//完全背包洛谷p1616
long long dp[10000003] = {0}; // j时间内的最大价值
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    long long t, m;
    cin >> t >> m;
    long long a, b; //无限采摘
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;               //时间,价值
        for (int j = 1; j <= t; j++) //时间
        {
            if (j - a < 0)//无法放入
            {
                
            }
            else
                dp[j] = max(dp[j], dp[j - a] + b);
            if (dp[j] > ans)
                ans = dp[j];
            // cout << dp[j]<<' ';
        }
        // cout << endl;
    }
    cout << ans;
    return 0;
}