#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans; //���
    int length;              //�����Ԫ�ظ���
    vector<int> track;       //·��
    bool *used;              //ʹ�ù�
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
        //����������nums �е�Ԫ��ȫ���� track �г���,��Ӵ�
        {
            ans.push_back(track);
            return;
        }
        for (int i = 0; i < length; i++) //��ѡ��
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
