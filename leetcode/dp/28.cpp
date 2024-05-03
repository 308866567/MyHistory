#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string haystack;
    string needle;
    long long ans;
    vector<int *> dp; //     ascii字符256个
                      //     dp[4]['A'] = 3 表示：
                      //     当前是状态 4，如果遇到字符 A，
                      //     pat 应该转移到状态 3
    Solution()
    {
        haystack = "aaacaaab";                    //文本串
        needle = "aaab";                          //模式串
        dp.resize(needle.size(), new int[256]()); //状态个数为模式字符个数
        kmp(needle);                              //构建dp数组
        // strStr(haystack, needle); //寻找答案
    };
    int strStr(string txt, string pat) // kmp,search函数
    {
        int n = txt.size();
        int m = pat.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            // 计算 pat 的下一个状态
            j = dp[j][(int)txt[i]];
            // 到达终止态，返回结果
            if (j == m)
            {
                // ans++;
                return i - m + 1; //返回匹配的串的首下标
            }
        }
        return -1;
    }
    int kmp(string pat) //构建dp数组
    {
        int m = pat.size();         //字符数
        dp[0][pat[0] - 'a'] = 1;    //当找到pat第一个字符时表示处在状态1
        int x = 0;                  //前一个状态
        for (int j = 1; j < m; j++) //从pat第二个字符开始
        {
            for (int c = 0; c < 256; c++) // ascii字符个数为256
            {
                dp[j][c] = dp[x][c]; //假设不匹配,状态回移为x,x为上一次循环更新的值
            }
            dp[j][pat[j]] = j - 1; //如果遇到下一位字符,进入下一个状态
            x = dp[x][pat[j]];     //更新x,x为前一个状态下遇到字符应进入哪个状态
        }
        return 0;
    }
};
int main()
{
    Solution a;
    cout << endl
         << 1;
    return 0;
}