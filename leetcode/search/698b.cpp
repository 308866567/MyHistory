#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// if (((used >> i) & 1) == 1) // �жϵ� i λ�Ƿ��� 1
// used |= 1 << i; // ���� i λ��Ϊ 1
// used ^= 1 << i; // ʹ��������㽫�� i λ�ָ�
bool cmp(pair<int, bool> a, pair<int, bool> b)
{
    return a.first > b.first;
}
class Solution
{
public:
    int size;             //����Ԫ�ظ���
    int bucket[17] = {0}; //���16���Ӽ�,Ԫ�ش���ÿ���Ӽ��ĺ�
    double sum = 0;       //ÿ���Ӽ��ĺ�
    vector<pair<int, bool>> memo;

public:
    //�ж��ܷ�ֳ�k���Ӽ����Ҹ����Ӽ������
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
    bool dfs2(vector<int> &nums, int k, int now, int target, int used) //�ݹ�k��Ͱ��ѡ��n������
    {
        //��������1�����һ���Ӽ�
        if (k == 0)
        {
            return true;
        }
        //Ͱװ����������һ��Ͱ
        if (bucket[k] == target)
        {
            bool res = dfs2(nums, k - 1, 0, target, used); // ����һ��Ͱ�� nums[0] ��ʼѡ����
            //����used
            memo.insert(lower_bound(memo.begin(),memo.end(),used,cmp),pair<int, bool>(used, res));
            return res;
        }
        if (binary_search(memo.begin(), memo.end(), used,cmp))
        {
            // �����������
            return ;
        }
        // n�������Ƿ�����Ӽ���
        for (int i = now; i < size; i++) //�Ӽ���һ��������n��ѡ��
        {
            if (((used >> i) & 1) == 1)
                continue;
            if (bucket[k] + nums[i] > target)
                continue;
            bucket[k] += nums[i];
            used |= 1 << i;                         // ���� i λ��Ϊ 1
            if (dfs2(nums, k, i + 1, target, used)) //�ݹ���һ�����ֵ��ж�
                return true;
            bucket[k] -= nums[i];
            used ^= 1 << i; // ʹ��������㽫�� i λ�ָ�
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