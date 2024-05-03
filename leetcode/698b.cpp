#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// if (((used >> i) & 1) == 1) // 判断第 i 位是否是 1
// used |= 1 << i; // 将第 i 位置为 1
// used ^= 1 << i; // 使用异或运算将第 i 位恢复
bool cmp(pair<int, bool> a, pair<int, bool> b)
{
    return a.first > b.first;
}
class Solution
{
public:
    int size;             //数组元素个数
    int bucket[17] = {0}; //最多16个子集,元素代表每个子集的和
    double sum = 0;       //每个子集的和
    vector<pair<int, bool>> memo;

public:
    //判断能否分成k个子集，且各个子集和相等
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        size = nums.size();
        if (k > size)
            return false;
        for (int i = 0; i < size; i++)
            sum += nums[i];
        if ((long)sum % k != 0)
            return false;
        sum /= k;
        if (sum != (int)sum)
            return false;
        return dfs2(nums, k, 0, sum, 0);
    }
    bool dfs2(vector<int> &nums, int k, int now, int target, int used) //递归k个桶，选择n个数字
    {
        //结束条件1到最后一个子集
        if (k == 0)
        {
            return true;
        }
        //桶装满了跳到下一个桶
        if (bucket[k] == target)
        {
            bool res = dfs2(nums, k - 1, 0, target, used); // 让下一个桶从 nums[0] 开始选数字
            //缓存used
            memo.insert(lower_bound(memo.begin(),memo.end(),used,cmp),pair<int, bool>(used, res));
            return res;
        }
        if (binary_search(memo.begin(), memo.end(), used,cmp))
        {
            // 避免冗余计算
            return ;
        }
        // n个数字是否放入子集中
        for (int i = now; i < size; i++) //子集放一个数字有n种选择
        {
            if (((used >> i) & 1) == 1)
                continue;
            if (bucket[k] + nums[i] > target)
                continue;
            bucket[k] += nums[i];
            used |= 1 << i;                         // 将第 i 位置为 1
            if (dfs2(nums, k, i + 1, target, used)) //递归下一个数字的判断
                return true;
            bucket[k] -= nums[i];
            used ^= 1 << i; // 使用异或运算将第 i 位恢复
        }
        return false;
    }
};
int main()
{
    vector<int> nums = {2, 2, 2, 2, 3, 4, 5};
    int k = 4;
    Solution aa;
    cout << aa.canPartitionKSubsets(nums, k);
}