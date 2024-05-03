#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const long long N = 2005;
ll g[N][N];
ll n, m;
void floyd()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if ( j != i && k != i)
				{
					g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
				}
			}
		}
	}
}


int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(g, 0x3f, sizeof(g));
	cin >> n >> m;
	ll u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		g[u][v] = min(g[u][v], w); //有向图
	}
	floyd();
	// 每个点的最短回路
	for (int i = 1; i <= n; i++)
	{
		if (g[i][i] >= 4557430888798830399)cout << -1 << "\n";
		else
			cout << g[i][i] << "\n";
	}
	return 0;
}
