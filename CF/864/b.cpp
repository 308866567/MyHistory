#include <iostream>
using namespace std;
const long N = 1e3 + 2;
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// 计算旋转180度后不匹配的格子个数
	// x旋转180度变n-x,x从0行
	long t;
	cin >> t;
	long n, k;
	long s = 0; // 0的个数
	char x;
	bool f = 0;
	while (t--)
	{
		bool arr[N][N] = {};
		s = 0;
		cin >> n >> k;
		f = n % 2; // n是奇数
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> x;
				if (x == '0')
				{
					if (i == j && f && i == n / 2)
						continue;
					arr[i][j] = 1;
					s++;
				}
			}
		}
		long ans = 0; // 需要改变颜色的格子个数
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j])
				{
					if (arr[n - i - 1][n - j - 1]) // 旋转后的位置已经是相同颜色
						continue;
					else
						ans++;
				}
			}
		}
		if (ans > k)
			cout << "NO\n";
		else
		{
			ans -= k;
			if (ans % 2&&!f)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
	return 0;
}
