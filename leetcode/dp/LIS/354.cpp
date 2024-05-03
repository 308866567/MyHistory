#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b) // a能否放入b
{
	if (a[1] == b[1] && a[0] == b[0]) //和堆顶相同可以放入
		return 1;
	// if (a[0] == b[0])
	// 	return a[1] > b[1];
	return a[1] <= b[1];
}
bool cmp1(vector<int> &a, vector<int> &b) // sort用
{
	if (a[0] == b[0])
	{
		if (a[1] > b[1]) //高度降序
			return 1;
		return 0;
	}
	else
		return a[0] < b[0]; //宽度升序
}
class Solution
{
public:
	int maxEnvelopes1() // dp做法,第85超时
	{
		vector<vector<int>> envelopes;
		envelopes = {{46, 89}, {50, 53}, {52, 68}, {72, 45}, {77, 81}};
		sort(envelopes.begin(), envelopes.end(), cmp1);
		int size = envelopes.size();
		int ans = 1;
		vector<int> dp(size, 1); //以nums[i]这个数结尾的最长递增子序列的长度
		// dp从0开始
		for (int i = 1; i < size; i++) //前i个信封从小到大排列
		{
			for (int j = 0; j < i; j++)
			{
				if (cmp(envelopes[j], envelopes[i])) // j可以放入i时
					dp[i] = max(dp[j] + 1, dp[i]);
			}
			if (dp[i] > ans)
				ans = dp[i];
		}
		cout << ans;
		return ans;
	}
	int maxEnvelopes() // 耐心排序,二分查找
	{
		vector<vector<int>> envelopes;
		envelopes = {{2,1},{4,1},{6,2},{8,3},{10,5},{12,8},{14,13},{16,21},{18,34},{20,55}};
		// go
		sort(envelopes.begin(), envelopes.end(), cmp1);
		int piles = 0, size = envelopes.size();
		vector<vector<int>> top;  //存储每堆的堆顶
		top.resize(size, {0, 0}); //初始化
		for (int i = 0; i < size; i++)
		{
			int l = 0, r = piles, mid;
			while (l < r) //左侧,左闭右开
			{
				mid = (l + r) / 2;
				if (cmp(envelopes[i], top[mid])) //可以放入i堆,向左找
				{
					r = mid;
				}
				else
					l = mid + 1;
			}
			if (l == piles)
			{
				piles++;
			}
			top[l] = envelopes[i];
		}
		cout << piles << endl;
		return piles;
	}
};
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	Solution a;
	a.maxEnvelopes();
	return 0;
}
