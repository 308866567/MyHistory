#include <bits/stdc++.h>
using namespace std;
//��ȫ�������p1616
long long dp[10000003] = {0}; // jʱ���ڵ�����ֵ
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    long long t, m;
    cin >> t >> m;
    long long a, b; //���޲�ժ
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;               //ʱ��,��ֵ
        for (int j = 1; j <= t; j++) //ʱ��
        {
            if (j - a < 0)//�޷�����
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