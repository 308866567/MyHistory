#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq()
    {string s;
        int ans = -1;
        s = "cbbd";                     // 4,bbbb
        int size = s.size();             //从0开始
        int dp[size + 1][size + 1] = {}; // i~j的最长回文子序列,
        for (int i = 0; i < size; i++)
            dp[i][i] = 1;                   //一个字符的回文子序列长度最大为1
                                            // base case  i>j的子序列不存在,长度为0
        for (int i = size - 1; i >= 0; i--) //从下往上
        {
            for (int j = i+1; j < size; j++) //防止j-1越界
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                if (dp[i][j] > ans)//更新答案
                    ans = dp[i][j];
            }
        }
        cout << ans;
    }
};int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    Solution a;
    a.longestPalindromeSubseq();
    return 0;
}