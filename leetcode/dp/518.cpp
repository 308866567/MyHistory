#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// dp[i][j] �Ķ������£�
// ��ֻʹ��ǰ i ����Ʒ�������ظ�ʹ�ã�
// ����������Ϊ j ʱ���� dp[i][j] �ַ�������װ������
class Solution
{
public:
    int change() //��Ҫ�ճ����ܽ��,Ӳ������
    {
        int amount;
        vector<int> coins;
        //��������Ӳ��,���޸���
        amount = 5, coins = {1, 2, 5}; // ans=4
        int n = coins.size();
        int dp[n + 1][amount + 1] = {}; // dp[Ӳ������][Ŀ����]
        // base case
        // dp[0][i]=0,0��Ӳ�Ҵ��κ�ֵ��Ϊ0
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1; //���ۼ���Ӳ�Ҵ�0��Ϊ1
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
                if (j - coins[i - 1] >= 0)
                    //��ֹԽ��
                    //ǰi-1��=j�����+ǰi��=j- coins[i - 1]�����,
                    //�������,��̶�ʹ��һ��iӲ��,��Ϊj����,���ұ���,���ظ�ʹ��iӲ��
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else //�޷�����ͼ̳�
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