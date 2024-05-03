#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int v[MAXN] = {0, 1, 2, 3, 4}; // 体积
int w[MAXN] = {0, 2, 4, 4, 5}; // 价值
int n = 4, m = 5;              //物品个数,最大容积//答案8
void dp1()                     // 01背包,i个元素,只能放一次
{
    //二维
    int f[MAXN][MAXN] = {0};         // f[i][j], j体积下前i个物品的最大价值
                                     //行表示前i个物品,列表示j体积
    for (int i = 1; i <= n; i++)     //第i个物品
        for (int j = 1; j <= m; j++) //枚举背包容量从1到最大
        {
            //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
            if (j < v[i])
                f[i][j] = f[i - 1][j];
            // 能装，需进行决策是否选择第i个物品
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            // j-v[i]表示腾出空间装当前物品
        }
    cout << f[n][m] << endl;
    //一维
    int ff[MAXN] = {0};                 // f[j]表示j体积下的最大价值
    for (int i = 1; i <= n; i++)        //第i个物品放入,更新数组
        for (int j = m; j >= v[i]; j--) //从后往前判断放入是否更好
        {                               //直到j放不下第i个物品
            ff[j] = max(ff[j], ff[j - v[i]] + w[i]);
            //不放入:为当前体积下的最大价值
            //放入:当前物品价值加上剩余体积下的最大价值
        }
    cout << ff[m] << endl;
}
void dp2() //完全背包,i种元素,可以重复使用
{
    //一维
    long long a, b, t = 2, dp[t]; //无限使用
    long long ans = 0;
    for (int i = 1; i <= m; i++)//一个物品循环t次
    {
        cin >> a >> b;               //当前i物品时间,价值
        for (int j = 1; j <= t; j++) //时间
        {
            if (j - a < 0) //无法放入,防止越界
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
    return;
}
//子串一定是连续的，而子序列不一定是连续的
// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序
void dp3() //找最长递增子序列的长度300,二分查找,扑克游戏,耐心排序
{
    // dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度
    // 即找第i个数前面的最长递增子序列,找个最大的接上去,初始时i=1,dp[i]=1

    // nums[5] = 3，既然是递增子序列，我们只要找到前面那些结尾比 3 小的子序列，
    // 然后把 3 接到这些子序列末尾，就可以形成一个新的递增子序列，而且这个新的子序列长度加1
    // vector<int> dp(size, 1); //以nums[i]这个数结尾的最长递增子序列的长度
    //     // dp从0开始
    //     for (int i = 1; i < size; i++) 
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (1) //num[j]可以接在num[i]后
    //                 dp[i] = max(dp[j] + 1, dp[i]);
    //         }
    //         if (dp[i] > ans)
    //             ans = dp[i];
    //     }
    //     cout << ans;
}
// 对于两个字符串求子序列的问题，
// 都是用两个指针i和j分别在两个字符串上移动，大概率是动态规划思路
void dp4() //两个字符串的子序列
{
    //最长公共子序列 力扣1143
    // 2.1 涉及两个字符串/数组时（比如最长公共子序列），dp 数组的含义如下：
    // 在子数组arr1[0..i]和子数组arr2[0..j]中，我们要求的子序列（最长公共子序列）长度为dp[i][j]。
    string text1 = "ezupkr";
    string text2 = "ubmrapg";
    long long size1 = text1.size();
    long long size2 = text2.size();
    int f[size1][size2]={}; // text1 0~i和text2 0~j的最长公共子序列长度
    f[0][0] = 0;
    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                f[i][j] = 1 + f[i - 1][j - 1];
            }
            else
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[size1][size2];
    //最长回文子序列 力扣516
    // 2.2 只涉及一个字符串/数组时（比如本文要讲的最长回文子序列），dp 数组的含义如下：
    // 在子数组array[i..j]中，我们要求的子序列（最长回文子序列）的长度为dp[i][j]。
    // dp[i][j]的值表示i到j字符里最长回文子序列的长度
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // cin >> n >> m;
    return 0;
}