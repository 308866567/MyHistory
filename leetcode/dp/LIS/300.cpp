#include <iostream>
#include <bits/stdc++.h>
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
				piles++;//新建一堆
				}
				top[left] = poker;//插入当前
			// }
		}
					cout << piles;
		return piles;
	}
};
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	Solution a;
	vector<int> x = {10,9, 2, 5, 3, 7, 101, 18};
	a.lengthOfLIS(x);
	return 0;
}
