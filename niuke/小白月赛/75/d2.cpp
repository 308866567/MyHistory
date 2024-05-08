#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;
const ll N = 1e3+2;
const ll INF = 0x3f3f3f3f;
bool a[N][N] = {};
ll dp[N][N] = {};//到当前位置最少需要变化几次
int n, m;
struct node
{
	int x;
	int y;
	node(int a, int b)
	{
		x = a;
		y = b;
	}
};
ll  bfs()
{
	deque<node>q;
	q.push_back(node(1,2));
	q.push_back(node(2,1));
	node temp(0,0);
	while (!q.empty())
	{
		node t = q.front();
		q.pop_front();
		if (t.x > n || t.y > m)
			continue;
		//添加下一步,右,下
		if(t.y+1<=m){
			temp = node(t.x, t.y + 1);
			q.push_back(temp); //右
		}
		if(t.x+1<=n){
			temp = node(t.x + 1, t.y);
			q.push_back(temp); //下
		}//更新结果
		ll l = dp[t.x][t.y - 1];
		if (a[t.x][t.y - 1] == a[t.x][t.y])
		{
			l++;
		}
		ll up = dp[t.x - 1][t.y];
		if (a[t.x - 1][t.y ] == a[t.x][t.y])
		{
			up++;
		}
		if(t.x==1) up=INF;
		if(t.y==1) l=INF;
		if (l < up)
		{
			dp[t.x][t.y] = l;
			a[t.x][t.y] = !a[t.x][t.y - 1];
			
		}
		else
		{
			dp[t.x][t.y] = up ;
			a[t.x][t.y] = !a[t.x - 1][t.y];
			
		}
	}
	return 1;
}
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	cin >> n >> m;
	char t;
	getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			t = getchar();
			if (t == '1')
				a[i][j] = 1;
		}
		getchar();
	}
	//	for(int i=1;i<=n;i++){
	//	dp[i][1]=dp[i][]	
	//	}
	bfs();
	//	for (int i = 1; i <= n; i++)
	//	{
	//		for (int j = 1; j <= m; j++)
	//		{
	//			cout << dp[i][j]<<' ';
	//		}
	//		cout << '\n';
	//	}
	//	cout << dp[n][m] << '\n';
	ll ans = n + m - 2 + dp[n][m];
	cout << ans;
	return 0;
}
