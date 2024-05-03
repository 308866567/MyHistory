#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// dp[i][j] 的定义如下：
// 若只使用前 i 个物品（可以重复使用）
// 当背包容量为 j 时，有 dp[i][j] 种方法可以装满背包
class Solution
{
public:
    int change() //需要凑出的总金额,硬币种类
    {
        int amount;
        vector<int> coins;
        //有限种类硬币,无限个数
        amount = 5, coins = {1, 2, 5}; // ans=4
        int n = coins.size();
        int dp[n + 1][amount + 1] = {}; // dp[硬币种类][目标金额]
        // base case
        // dp[0][i]=0,0个硬币凑任何值都为0
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1; //无论几个硬币凑0都为1
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
                if (j - coins[i - 1] >= 0)
                    //防止越界
                    //前i-1种=j的情况+前i种=j- coins[i - 1]的情况,
                    //如果放入,则固定使用一个i硬币,因为j是列,往右遍历,会重复使用i硬币
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else //无法放入就继承
                    dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= n; k++)
            {
                for (int l = 0; l <= amount; l++)
                {
                    cout << dp[k][l] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= amount; j++)
        //     {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        return dp[n][amount];
    }
};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    Solution a;
    a.change();
    return 0;
}