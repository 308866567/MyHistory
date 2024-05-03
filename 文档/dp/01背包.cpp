#include <bits/stdc++.h>
using namespace std;
int dp[1003] = {0}; // j时间内的最大价值
//洛谷p1048
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    int t, m;
    cin >> t >> m;
    int a[m + 3][2];
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i][0] >> a[i][1]; //时间,价值
    }
    long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j > 0; j--)
        {
            if (j - a[i][0] < 0)
                continue;
            dp[j] = max(dp[j], dp[j - a[i][0]] + a[i][1]);
            if (dp[j] > ans)
                ans = dp[j];
        }
    }
    cout << ans;
    return 0;
}