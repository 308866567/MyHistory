#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans; //结果
    int length;              //给予的元素个数
    vector<int> track;       //路径
    bool *used;              //使用过
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        length = nums.size();
        bool *used = new bool[length]();
        backtrack(nums, track, used);
        delete used;
        return ans;
    }
    void backtrack(vector<int> &nums, vector<int> &track, bool *used)
    {
        if (track.size() == length)
        //结束条件：nums 中的元素全都在 track 中出现,添加答案
        {
            ans.push_back(track);
            return;
        }
        for (int i = 0; i < length; i++) //做选择
        {
            if (used[i])
            {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, track, used);
            track.pop_back();
            used[i] = false;
        }
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    class Solution s;
    s.permute(nums);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<s.ans[i][j];
        }
        cout<<endl;
    }
}
