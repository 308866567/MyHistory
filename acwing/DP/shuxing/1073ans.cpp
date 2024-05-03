#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010, M = N << 1, INF = 0x3f3f3f3f;

int n;
int h[N], e[M], w[M], ne[M], idx;
int d1[N], d2[N], up[N];
int s1[N], s2[N];//记录最长路和次长路的节点

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
void dfs1(int u, int father)
{
	// d1[u] = d2[u] = -INF;  //这题所有边权都是正的，可以不用初始化为负无穷
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == father) continue;
		dfs1(j, u);
		if (d1[j] + w[i] >= d1[u])//叶子节点的最长路+到父节点的距离>父节点的最长路
		{
			d2[u] = d1[u], s2[u] = s1[u];
			d1[u] = d1[j] + w[i], s1[u] = j;
		}
		else if (d1[j] + w[i] > d2[u])
		{
			d2[u] = d1[j] + w[i], s2[u] = j;
		}
	}
	// if (d1[u] == -INF) d1[u] = d2[u] = 0; //特判叶子结点
}
void dfs2(int u, int father)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == father) continue;
		if (s1[u] == j) up[j] = w[i] + max(up[u], d2[u]);   //son_u  = j，则用次大更新
		else up[j] = w[i] + max(up[u], d1[u]);              //son_u != j，则用最大更新
		dfs2(j, u);
	}
}
void out(int *x)
{
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << ' ';
			if(i%10==0) cout<<"\n";
	}
	cout << "\n";
	
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	memset(h, -1, sizeof h);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++ )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}

	dfs1(1, -1);
	dfs2(1, -1);
	out(d1);
	out(d2);
	out(up);


	int res = INF;
	for (int i = 1; i <= n; i ++ ) res = min(res, max(d1[i], up[i]));
	printf("%d\n", res);

	return 0;
}
