#include <iostream>
#include <bits/stdc++.h>
// ����������� LIS ����300
// ������ ���������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳��
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums) //���ֽⷨ
    {
        vector<int> top; //�洢�ƶ�
        int piles = 0;
        int size = nums.size();
        top.resize(size, 0);
        for (int i = 0; i < size; i++)
        {
            int poker = nums[i];
            int left = 0, right = piles;
            while (left < right) //�Ѷ����ڵ�ǰ�Ƶ������
            {
                int mid = (left + right) / 2;
                if (top[mid] > poker) //��ǰ��С�ڶѶ�,������
                {
                    right = mid;
                }
                else if (top[mid] < poker)
                {
                    left = mid + 1;
                }
                else
                    right = mid;
            }
            //û�ҵ����ʵ��ƶ�,�½�һ�Ѳ��뵱ǰ��
            if (left == piles)
            {
                piles++; //�½�һ��
            }
            top[left] = poker; //�������Ʒŵ��Ѷ�
        }
        cout << piles;
        return piles;
    }
    int maxEnvelopes1(vector<int> &nums) // ����dp�ⷨ j,0~i
    {
        int size = nums.size();
        int ans = 1;
        // base case
        vector<int> dp(size, 1); //��nums[i]�������β������������еĳ���
        // dp��0��ʼ
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i]>nums[j]) // num[j]���Խ���num[i]��
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            if (dp[i] > ans)
                ans = dp[i];
        }
        cout <<endl<< ans;
        return ans;
    }
};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    Solution a;
    vector<int> x = {10, 9, 2, 5, 3, 7, 101, 18};
    a.lengthOfLIS(x);
    a.maxEnvelopes1(x);
    return 0;
}