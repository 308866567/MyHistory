#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long N = 1e4 + 5, M = N * 2;
int h[N], e[M], w[M], ne[M], idx;//邻接表
ll ans[N], d1[N], d2[N];
ll s1[N], s2[N];
ll n;
/*
换根DP 一般分为三个步骤：
指定任意一个根节点
一次dfs遍历，统计出当前子树内的节点对当前节点的贡献
一次dfs遍历，统计出当前节点的父节点对当前节点的贡献，然后合并统计答案
*/
inline void add(ll a, ll b, ll c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
ll dfs(int u, int father)
{
	ll dist = 0;//计算当前节点到其后续各个节点的最远距离和次长距离
	//次长距离用于计算父节点的贡献
	for (int i = h[u]; i != -1; i = ne[i])
	{
		ll j = e[i];
		if (j == father)
			continue;
		dist = dfs(j, u) + w[i];
		if (dist >= d1[u])
		{
			s2[u] = s1[u];
			s1[u] = j;//u节点的最长路径上的下一个节点
			d2[u] = d1[u];
			d1[u] = dist;//u节点的次长路径上的下一个节点
		}
		else if (dist > d2[u])
		{
			d2[u] = dist;
			s2[u] = j;
		}
	}
	return d1[u];
}
ll dfs2(int u, int father) //父节点到当前节点的距离
{
	//1当前节点在上一个节点的最长路径上时
	//2不在最长路径上时
	for (int i = h[u]; i != -1; i = ne[i])
	{
		ll j = e[i];
		if (j == father)
			continue;
		//先更新子节点j,当遍历到子节点时,父节点的贡献已经知道了
		if (j == s1[u])//j在最长路径上
		{
			ans[j] = w[i] + max(ans[u], d2[u]); //父节点的次长或者父节点的父节点路径
		}
		else
		{
			ans[j] = w[i] + max(ans[u], d1[u]); //父节点的最长或者父节点的父节点路径
		}
		dfs2(j, u);
	}
	return 0;
}
void out(ll *x)
{
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << ' ';
		if (i % 10 == 0) cout << "\n";
	}
	cout << "\n";
	
}
int main()
{
	//freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	memset(h, -1, sizeof(h));
	ll a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	dfs(1, -1);
	dfs2(1, -1);
	//	out(d1);
	//	out(d2);
	//	out(ans);
	ll minn = 1e9;
	for (int i = 1; i <= n; i++)
	{
		minn = min(minn, max(ans[i], d1[i]));
	}
	cout << minn;
	return 0;
}
//点到树中其他结点的最远距离可以分为
//max(包含子节点的路径-往下走,包含父节点的路径-往上走)
//父节点的贡献是父节点中包含子节点的路径中最长或次长
//最长或次长的点一定不相同?
//邻接表保证最长和次长路径的起始子节点一定不同
//最后遍历n个节点取min
