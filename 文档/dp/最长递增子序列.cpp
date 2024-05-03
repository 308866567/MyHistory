#include <iostream>
#include <bits/stdc++.h>
// 最长递增子序列 LIS 力扣300
// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums) //二分解法
    {
        vector<int> top; //存储牌堆
        int piles = 0;
        int size = nums.size();
        top.resize(size, 0);
        for (int i = 0; i < size; i++)
        {
            int poker = nums[i];
            int left = 0, right = piles;
            while (left < right) //堆顶大于当前牌的最左堆
            {
                int mid = (left + right) / 2;
                if (top[mid] > poker) //当前牌小于堆顶,往左找
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
            //没找到合适的牌堆,新建一堆插入当前牌
            if (left == piles)
            {
                piles++; //新建一堆
            }
            top[left] = poker; //把这张牌放到堆顶
        }
        cout << piles;
        return piles;
    }
    int maxEnvelopes1(vector<int> &nums) // 常规dp解法 j,0~i
    {
        int size = nums.size();
        int ans = 1;
        // base case
        vector<int> dp(size, 1); //以nums[i]这个数结尾的最长递增子序列的长度
        // dp从0开始
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i]>nums[j]) // num[j]可以接在num[i]后
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