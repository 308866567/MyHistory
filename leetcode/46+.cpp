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
    if (first == numsSize) {    //所有的数都填过了,保存,递归终止
        int *result = malloc(sizeof(int) * numsSize);
        memcpy(result, nums, sizeof(int) * numsSize);      //注意memcpy的大小sizeof(type) * size
        ans[sz++] = result;
        return;
    }
    for (int i = first; i < numsSize; i++) {    //[first, n - 1]都是待填的数,遍历所有待填的数
        swap(nums + i, nums + first);           //nums[first]存放第一个待遍历的数
        dfs(nums, numsSize, first + 1, ans);    //上一行将nums[first]填入路径,对填第first+1个数而言,[first+1, n-1]是待填的
        swap(nums + i, nums + first);           //回溯
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int total = 1;
    for (int i = 0; i < numsSize; i++)
        total *= (i + 1);
    int **ans = malloc(sizeof(int *) * total);
    sz = 0;     //不能在全局变量时赋值，否则溢出，leetcode跑用例时，只初始化一次，之后的用例，全局变量就不是从0开始
    dfs(nums, numsSize, 0, ans);

    *returnSize = sz;
    *returnColumnSizes = malloc(sizeof(int *) * sz);
    for (int i = 0; i < sz; i++)
        (*returnColumnSizes)[i] = numsSize;
    return ans;
}


作者：JoKong
链接：https://leetcode.cn/problems/permutations/solution/by-jokong-mvmh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。