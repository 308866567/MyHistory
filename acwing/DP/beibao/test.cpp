#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef int ll;
const ll N = 2e7 + 10;
//
struct node
{
	ll v, w;
} a[N];
ll dp[N];
ll n, v;
/*
70 3
71 100
69 1
1 2
*/
void wanquan(){
	for(int i=1;i<=v;i++)//物品，可以无限选
	{
		for(int j=a[i].v;j<=n;j++)//限制
		{
			if(j>=a[i].v)
				dp[j]=max(dp[j],dp[j-a[i].v]+a[i].w);
		}
	}
	return ;
}
void bei01(){
	//物品只能用一次
	for (int i = 1; i <= v; i++) //物品
	{
		for (int j = 0; j <= n; j++) 
		{
			//dp[i][j]=dp[i-1][j];
			//if (j>=a[i].v)
//				dp[i][j] =max(dp[i][j], dp[i-1][j-a[i].v] + a[i].w);
		}
	}
}
int main()
{
	//freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> v;
	for (int i = 1; i <= v; i++)
	{
		cin >> a[i].v >> a[i].w;
	}
	wanquan();
	cout<<dp[n];
	return 0;
}
