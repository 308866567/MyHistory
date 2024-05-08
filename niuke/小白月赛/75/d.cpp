#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 5;//1e3+2;
const ll INF = 0x3f3f3f3f;
bool a[N][N] = {};
bool b[N][N] = {};
ll dp[N][N] = {};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	int n, m;
	cin >> n >> m;
	char t;
	getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			t = getchar();
			if (t == '1') a[i][j] = 1;
			b[i][j] = a[i][j];
		}
		getchar();
	}
	cout << dp[n][m];
	return 0;
}
