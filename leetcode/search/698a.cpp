#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int bucket[17] = {0}; //���16���Ӽ�,Ԫ�ش���ÿ���Ӽ��ĺ�
    double sum = 0;       //ÿ���Ӽ��ĺ�
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) //�ж��ܷ�ֳ�k���Ӽ����Ҹ����Ӽ������
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
    //�ݹ�n�����֣�ÿ�����ֿ���ѡ��k���Ӽ�
    bool dfs1(vector<int> &nums, int k, int now, int target)
    {
        //��������1���ֵݹ鵽���һ��ʱ2ÿ���Ӽ������
        if (now == nums.size() )
        {
            // for (int i = 0; i < k; i++)
            // {
            //     if (bucket[i] != target)
            //         return false;
            // }
            return true;
        }
        //����ѡ��һ���Ӽ�����
        for (int i = 0; i < k; i++)
        {
            //�Ӽ�����ʱ��
            if (bucket[i] + nums[now] > target)
                continue;
            if (i>0&&bucket[i] == bucket[i-1])//��֦,����������
                continue;
            bucket[i] += nums[now]; //���ֽ��뵱ǰ�Ӽ�
            if (dfs1(nums, k, now + 1, target))
                return true;        //�ݹ������һ�����ֵ�ѡ��
            bucket[i] -= nums[now]; //����
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