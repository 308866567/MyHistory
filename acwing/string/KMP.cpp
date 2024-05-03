#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 1000010;
int n, m;
int ne[N];
char s[M], p[N];
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> n >> p + 1 >> m >> s + 1;
	// ne[1]=0首位始终为0
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j != 0 && p[i] != p[j + 1])
			j = ne[j];
		if (p[i] == p[j + 1])
			j++;
		ne[i] = j; // 记录到i位时已经匹配上了多少
	}
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j != 0 && s[i] != p[j + 1]) // 不相等时,i位需要重新和j+1比较,j表示已经匹配上了j位
			j = ne[j];                // j需要>=1,即j不为起点 ,j=0表示没有碰到p串开头
		if (s[i] == p[j + 1])         // 相等时
			j++;
		if (j == n) // 如果匹配到
		{
			printf("%d ", i - n); // 起始下标
			j = ne[j];
		}
	}
	return 0;
}
