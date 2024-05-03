#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1030;
bool ans[N][N] = {}; //1代表*
int n;
void dfs(int n, int x, int y, bool f)//1表示好豆子
{
	int len = 3 * (1 << n);
	if (n == 1)
	{
		//f表示好豆子
		for (int i = x; i < x + len; i++)
		{
			for (int j = y; j < y + len; j++)
			{
				ans[i][j] = f;
			}
		}
		for (int i = x + len / 2; i < x + len; i++)
		{
			for (int j = y + len / 2; j < y + len; j++)
			{
				ans[i][j] = !f;
			}
		}
		return ;
	}
	dfs(n - 1, x, y, f);
	dfs(n - 1, x + len / 2, y, f);
	dfs(n - 1, x, y + len / 2, f);
	dfs(n - 1, x + len / 2, y + len / 2, !f);
	return ;
}
void out()
{
	int len = 3 * (1 << n);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (ans[i][j]) cout << "*";
			else cout << '.';
		}
		cout << "\n";
	}
}
int main()
{
	//freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	cin >> n;
	dfs(n, 0, 0, n%2);
	out();
	return 0;
}
