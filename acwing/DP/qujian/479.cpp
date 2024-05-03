#include <iostream>
using namespace std;
typedef long long ll;
const long long N = 60;
int w[N];
ll dp[N][N], p[N][N];
//[i,j]的节点组成的加分二叉树
void dfs(ll l, ll r)
{
	ll k = p[l][r];
	if (l > r)
		return ;
	cout << k << " ";
	dfs(l, k - 1);
	dfs(k + 1, r);
	return ;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}


	for (int len = 1; len <= n; len++)
	{
		for (int l = 1; l + len - 1 <= n; l++) //环形转为单链
		{
			int r = l + len - 1;
			dp[l][r] = 0;//最高分
			if (len == 1)
			{
				dp[l][r] = w[l];
				p[l][r] = l;
					continue;
			}

			for (int k = l; k <= r; k++)//最后一次合并的节点
			{
//			subtree的左子树的加分 × subtree的右子树的加分 ＋ subtree的根的分数?
				ll left = l > k ? 1 : dp[l][k - 1];//判空
				ll right = k + 1 > r ? 1 : dp[k + 1][r];
				ll t = left * right + w[k];
				if (t > dp[l][r])
				{
					dp[l][r] = t;
					p[l][r] = k; //这个区间高分子树的根节点
					//左孩子为p[l][k-1],右为p[k+1][r]
				}
			}
//			cout << dp[l][r] << ' ';
		}
//		cout << '\n';
	}
	cout << dp[1][n] << "\n";
	dfs(1, n);
	return 0;
}



