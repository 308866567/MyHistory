#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
long long ans1 = 0, ans2 = 0;
int n, m;
char **g;
void out()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << g[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "\n";
}
bool dfs(int x, int y, bool &f)
{
	if (g[x][y] == '0')
	{
		return f;
	}
	if (g[x][y] > '1')
		f = 1;
	g[x][y] = '0';
	int tx, ty;
	for (int i = 0; i < 4; i++)
	{
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		if (tx < 0 || ty < 0 || tx >= n || ty >= m)
			continue;
		dfs(tx, ty, f);
	}
	return f;
}
int main()
{
	// freopen("C://Temp//in.txt", "r", stdin);
	cin >> n >> m;
	g = new char *[n + 1];
	for (int i = 0; i < n; i++)
		g[i] = new char[m + 1];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> g[i][j];
		}
		//  ‰»Î
	}

	bool f = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			f = 0;
			if (g[i][j] == '0')
				continue;
			else
			{
				if (dfs(i, j, f))
					ans2++;
				ans1++;
			}
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
