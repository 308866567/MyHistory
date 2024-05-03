#include <iostream>
using namespace std;
int main()
{ 
return 0;
}
int sz;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void dfs(int *nums, int numsSize, int first, int **ans) {
    if (first == numsSize) {    //���е����������,����,�ݹ���ֹ
        int *result = malloc(sizeof(int) * numsSize);
        memcpy(result, nums, sizeof(int) * numsSize);      //ע��memcpy�Ĵ�Сsizeof(type) * size
        ans[sz++] = result;
        return;
    }
    for (int i = first; i < numsSize; i++) {    //[first, n - 1]���Ǵ������,�������д������
        swap(nums + i, nums + first);           //nums[first]��ŵ�һ������������
        dfs(nums, numsSize, first + 1, ans);    //��һ�н�nums[first]����·��,�����first+1��������,[first+1, n-1]�Ǵ����
        swap(nums + i, nums + first);           //����
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int total = 1;
    for (int i = 0; i < numsSize; i++)
        total *= (i + 1);
    int **ans = malloc(sizeof(int *) * total);
    sz = 0;     //������ȫ�ֱ���ʱ��ֵ�����������leetcode������ʱ��ֻ��ʼ��һ�Σ�֮���������ȫ�ֱ����Ͳ��Ǵ�0��ʼ
    dfs(nums, numsSize, 0, ans);

    *returnSize = sz;
    *returnColumnSizes = malloc(sizeof(int *) * sz);
    for (int i = 0; i < sz; i++)
        (*returnColumnSizes)[i] = numsSize;
    return ans;
}


���ߣ�JoKong
���ӣ�https://leetcode.cn/problems/permutations/solution/by-jokong-mvmh/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������