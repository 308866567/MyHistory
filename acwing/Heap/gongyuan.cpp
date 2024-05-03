#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long N = 4e4 + 4;
unordered_map<ll, unordered_map<ll, ll>> g;

//

ll te, fe, s;
ll t, f, n, m;
void floyd2()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k)
				continue;
			for (int j = 1; j <= n; j++)
			{
				if (j == k || j == i )
					continue;
				if (g[i][j]==0) g[i][j] =0x3f3f3f3f;
				if(g[i][k]==0) g[i][k]=0x3f3f3f3f;
				if(g[k][j]==0 )g[k][j]=0x3f3f3f3f;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k || g[i].count(k) == 0)
				continue;
			for (int j = 1; j <= n; j++)
			{
				if (j == k || j == i || g[k].count(j) == 0)
					continue;
				if (g[i].count(j) == 0) g[i][j] = 0x3f3f3f3f;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll aim;
	cin >> te >> fe >> s;
	cin >> t >> f >> aim >> m;
	ll x, y;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		n = max(x, y);
		g[x][y] = 1;
		g[y][x] = 1;
	}
	ll ans = 0x3f3f3f3f;
	floyd2();
	for (int i = 1; i <= n; i++)
	{
		if(g[t][i]>=ans||g[f][i]>=ans||g[i][aim]>=ans)
			continue;
//		if (!(g[t].count(i) && g[f].count(i) && g[i].count(aim)))
//			continue;
		ans = min(ans, g[t][i] * te + g[f][i] * fe + g[i][aim] * (te + fe - s));
	}
	if(ans>=0x3f3f3f) cout<<"-1";
	else
		cout << ans;
	return 0;
}
