#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 50;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

//
ll n, m;
ll x, y;
ll f[N][N];
bool check(ll i, ll j)
{
	if(i==n&&j==m) 
		return 0;
	if (i == x && j == y)
		return 1;
	if (5 == (i - x) * (i - x) + (j - y) * (j - y))
		return 1;
	else return 0;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	cin >> n >> m;
	cin >> x >> y;
	n++, m++, x++, y++;
	f[0][1]=1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (check(i, j))
				f[i][j] = 0;
			else
				f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<f[i][j]<<' ';
//		}
//		cout<<"\n";
//	}
	cout << f[n][m];
	return 0;
}
