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
	// ne[1]=0��λʼ��Ϊ0
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j != 0 && p[i] != p[j + 1])
			j = ne[j];
		if (p[i] == p[j + 1])
			j++;
		ne[i] = j; // ��¼��iλʱ�Ѿ�ƥ�����˶���
	}
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j != 0 && s[i] != p[j + 1]) // �����ʱ,iλ��Ҫ���º�j+1�Ƚ�,j��ʾ�Ѿ�ƥ������jλ
			j = ne[j];                // j��Ҫ>=1,��j��Ϊ��� ,j=0��ʾû������p����ͷ
		if (s[i] == p[j + 1])         // ���ʱ
			j++;
		if (j == n) // ���ƥ�䵽
		{
			printf("%d ", i - n); // ��ʼ�±�
			j = ne[j];
		}
	}
	return 0;
}
