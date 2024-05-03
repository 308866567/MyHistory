#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b) // a�ܷ����b
{
	if (a[1] == b[1] && a[0] == b[0]) //�ͶѶ���ͬ���Է���
		return 1;
	// if (a[0] == b[0])
	// 	return a[1] > b[1];
	return a[1] <= b[1];
}
bool cmp1(vector<int> &a, vector<int> &b) // sort��
{
	if (a[0] == b[0])
	{
		if (a[1] > b[1]) //�߶Ƚ���
			return 1;
		return 0;
	}
	else
		return a[0] < b[0]; //�������
}
class Solution
{
public:
	int maxEnvelopes1() // dp����,��85��ʱ
	{
		vector<vector<int>> envelopes;
		envelopes = {{46, 89}, {50, 53}, {52, 68}, {72, 45}, {77, 81}};
		sort(envelopes.begin(), envelopes.end(), cmp1);
		int size = envelopes.size();
		int ans = 1;
		vector<int> dp(size, 1); //��nums[i]�������β������������еĳ���
		// dp��0��ʼ
		for (int i = 1; i < size; i++) //ǰi���ŷ��С��������
		{
			for (int j = 0; j < i; j++)
			{
				if (cmp(envelopes[j], envelopes[i])) // j���Է���iʱ
					dp[i] = max(dp[j] + 1, dp[i]);
			}
			if (dp[i] > ans)
				ans = dp[i];
		}
		cout << ans;
		return ans;
	}
	int maxEnvelopes() // ��������,���ֲ���
	{
		vector<vector<int>> envelopes;
		envelopes = {{2,1},{4,1},{6,2},{8,3},{10,5},{12,8},{14,13},{16,21},{18,34},{20,55}};
		// go
		sort(envelopes.begin(), envelopes.end(), cmp1);
		int piles = 0, size = envelopes.size();
		vector<vector<int>> top;  //�洢ÿ�ѵĶѶ�
		top.resize(size, {0, 0}); //��ʼ��
		for (int i = 0; i < size; i++)
		{
			int l = 0, r = piles, mid;
			while (l < r) //���,����ҿ�
			{
				mid = (l + r) / 2;
				if (cmp(envelopes[i], top[mid])) //���Է���i��,������
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
