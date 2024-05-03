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
    vector<int *> dp; //     ascii�ַ�256��
                      //     dp[4]['A'] = 3 ��ʾ��
                      //     ��ǰ��״̬ 4����������ַ� A��
                      //     pat Ӧ��ת�Ƶ�״̬ 3
    Solution()
    {
        haystack = "aaacaaab";                    //�ı���
        needle = "aaab";                          //ģʽ��
        dp.resize(needle.size(), new int[256]()); //״̬����Ϊģʽ�ַ�����
        kmp(needle);                              //����dp����
        // strStr(haystack, needle); //Ѱ�Ҵ�
    };
    int strStr(string txt, string pat) // kmp,search����
    {
        int n = txt.size();
        int m = pat.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            // ���� pat ����һ��״̬
            j = dp[j][(int)txt[i]];
            // ������ֹ̬�����ؽ��
            if (j == m)
            {
                // ans++;
                return i - m + 1; //����ƥ��Ĵ������±�
            }
        }
        return -1;
    }
    int kmp(string pat) //����dp����
    {
        int m = pat.size();         //�ַ���
        dp[0][pat[0] - 'a'] = 1;    //���ҵ�pat��һ���ַ�ʱ��ʾ����״̬1
        int x = 0;                  //ǰһ��״̬
        for (int j = 1; j < m; j++) //��pat�ڶ����ַ���ʼ
        {
            for (int c = 0; c < 256; c++) // ascii�ַ�����Ϊ256
            {
                dp[j][c] = dp[x][c]; //���費ƥ��,״̬����Ϊx,xΪ��һ��ѭ�����µ�ֵ
            }
            dp[j][pat[j]] = j - 1; //���������һλ�ַ�,������һ��״̬
            x = dp[x][pat[j]];     //����x,xΪǰһ��״̬�������ַ�Ӧ�����ĸ�״̬
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