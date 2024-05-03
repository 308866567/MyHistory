#include <iostream>
#define INF 0x3f3f3f3f3f
using namespace std;
typedef long long ll;
const long long N = 205;
typedef ll da;
int n;
da dp[N][N];//i°´Ë³Ðò¾ÛºÏµ½j
da arr[2 * N];
void out()
{
	for (int i = 1; i <= 2 * n; i++)
	{
		for (int j = 1; j <= 2 * n; j++)
		{
			printf("%10lld ", dp[i][j]);
		}
		cout << "\n";
	}
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	for (int len = 2; len <= n; len++)
	{
		for (int l = 1; l + len - 1 < 2 * n; l++)
		{
			int r = l + len - 1;
			dp[l][r] = 0;
			for (int k = l; k < r; k++)
			{
				dp[l][r] = max(dp[l][r],
				               dp[l][k] + dp[k+1][r] + arr[l] * arr[k+1] * arr[r+1]);
			}
//			cout<<dp[l][r]<<' ';
		}
//		cout<<'\n';
	}
//	out();
	da ans = -1;
	for (int l = 1; l + n - 1 < 2 * n; l++)
	{
		int r = l + n - 1;
		ans = max(ans, dp[l][r]);
	}
	cout << ans;
	return 0;
}
