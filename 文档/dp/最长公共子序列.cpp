#include <iostream>
#include <string>
using namespace std;//力扣1143
int dp()//i和j 0~字符串长度
{
	string text1 = "ezupkr";
	string text2 = "ubmrapg";
	long long size1 = text1.size();
	long long size2 = text2.size();
	int f[103][103] ; // text1 0~i和text2 0~j的最长公共子序列长度
	f[0][0] = 0;
	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if (text1[i - 1] == text2[j - 1])
			{
				f[i][j] = 1 + f[i - 1][j - 1];
			}
			else
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			cout << f[i][j] << ' ';
		}
		cout << endl;
	}
	return f[size1][size2];
}
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	dp();
	return 0;
}
