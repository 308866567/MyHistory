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
        int size = s.size();             //��0��ʼ
        int dp[size + 1][size + 1] = {}; // i~j�������������,
        for (int i = 0; i < size; i++)
            dp[i][i] = 1;                   //һ���ַ��Ļ��������г������Ϊ1
                                            // base case  i>j�������в�����,����Ϊ0
        for (int i = size - 1; i >= 0; i--) //��������
        {
            for (int j = i+1; j < size; j++) //��ֹj-1Խ��
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                if (dp[i][j] > ans)//���´�
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