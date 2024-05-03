#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int lengthOfLIS(vector<int> &nums) //���ֽⷨ
	{
		vector<int> top; //�洢�ƶ�
		int piles = 0;
		int size = nums.size();
		top.resize(size, 0);
		for (int i = 0; i < size; i++)
		{
			int poker = nums[i];
			int left = 0, right = piles;
			while (left < right) //�Ѷ����ڵ�ǰ�Ƶ������
			{
				int mid = (left + right) / 2;
				if (top[mid] > poker) //��ǰ��С�ڶѶ�,������
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
			//û�ҵ����ʵ��ƶ�,�½�һ�Ѳ��뵱ǰ��
			if (left == piles)
			{
				piles++;//�½�һ��
				}
				top[left] = poker;//���뵱ǰ
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
