#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int bucket[17] = {0}; //最多16个子集,元素代表每个子集的和
    double sum = 0;       //每个子集的和
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) //判断能否分成k个子集，且各个子集和相等
    {
        sort(nums.begin(), nums.end(), greater<int>());
        if (k > nums.size())
            return false;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if ((long)sum % k != 0)
            return false;
        sum /= k;
        if (sum != (int)sum)
            return false;
        // dfs1(nums, k, 0, sum);
        return dfs1(nums, k, 0, sum);
        ;
    }
    //递归n个数字，每个数字可以选择k个子集
    bool dfs1(vector<int> &nums, int k, int now, int target)
    {
        //结束条件1数字递归到最后一个时2每个子集和相等
        if (now == nums.size() )
        {
            // for (int i = 0; i < k; i++)
            // {
            //     if (bucket[i] != target)
            //         return false;
            // }
            return true;
        }
        //数字选择一个子集加上
        for (int i = 0; i < k; i++)
        {
            //子集满的时候
            if (bucket[i] + nums[now] > target)
                continue;
            if (i>0&&bucket[i] == bucket[i-1])//剪枝,填满就跳过
                continue;
            bucket[i] += nums[now]; //数字进入当前子集
            if (dfs1(nums, k, now + 1, target))
                return true;        //递归进入下一个数字的选择
            bucket[i] -= nums[now]; //撤销
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    Solution aa;
    cout << aa.canPartitionKSubsets(nums, k);
}