#include <iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const long long N = 1e4 + 5, M = N * 2;
//树的最长路径,也称为直径
//状态表示-集合
//以节点i为根的子树中,从子树某个节点到i的最长路为f1[i],次长路为f2[i]
int h[N], e[M], w[M], ne[M], idx;//邻接表
ll ans;
ll n;
ll a, b, c;
inline void add(int a, int b, int c)
{
	e[idx] = b;//当前边终点
	w[idx] = c;//当前边权值
	ne[idx] = h[a];//邻接表上一个节点索引
	h[a] = idx++;
}
ll dfs(int u, int father)
{
//	cout<<u<<' ';
	ll dist = 0;//最长路径
	ll d1 = 0, d2 = 0;//最长路径和次长路径
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j == father)
			continue;//防止死循环
		ll d = dfs(j, u) + w[i]; //子节点的最长路径
		dist = max(dist, d);
		if (d >= d1)
		{
			d2 = d1;
			d1 = d;
		}
		else if (d > d2) d2 = d;
	}
	//最长路径为根节点子树的最长加次长
	ans = max(ans, d1 + d2); //每个节点都要判断一次答案
	return dist;//返回最长路径
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	memset(h, -1, sizeof(h));
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	dfs(1, -1);
	cout << ans;
	return 0;
}




