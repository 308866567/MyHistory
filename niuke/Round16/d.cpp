#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef  int ll;
const long long N = 1e5 + 10, M = 1e5 + 10, INF = 0x3f3f3f3f;
ll n, m;
ll p[N+20];//x的父节点
vector<ll> ans;
struct Edge { //存储边
	ll id,a, b, w;
	bool p;
	bool operator <(const Edge &t)const {
		return w < t.w;
	}
} edges[M];
//判断是否会产生回路的方法为：使用并查集
//在最小生成树的为一个集合
//如果边上的这两个顶点在一个集合中，说明两个顶点已经连通，这条边不要
ll find(ll x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
ll kruskal() { //无向图
	sort(edges+1, edges +1+ m);
	for (int i = 1; i <= n; i++) 
		p[i] = i;
	ll res = 0, cnt = 0;//最小生成树的树边权重之和
	ll a, b, w;
	//必选计划
	for (int i = 1; i <= m; i++) {
		if (edges[i].p) {
			a = edges[i].a;
			b = edges[i].b;
			w = edges[i].w;
			ans.push_back(edges[i].id);
			//连通
			a = find(a), b = find(b);
			p[a] = b;//a->b
			res += w;
			cnt++;
		}
	}
	for (int i = 1; i <= m; i++) { //权值从小到大
		if (edges[i].p) 
			continue;
		a = edges[i].a;
		b = edges[i].b;
		w = edges[i].w;
		a = find(a), b = find(b);
		//如果这个边与之前选择的所有边不会组成回路，就选择这条边
		if (a != b) {
			p[a] = b;//a->b
			res += w;
			cnt++;
			ans.push_back(edges[i].id);
		}
	}
	//直到具有 n 个顶点的连通网筛选出来 n-1 条边为止
	if (cnt < n - 1)
	{
		cout << "-1\n";
	}
	else {
		ll s = ans.size();
		cout << s << "\n";
		for (int i = 0; i < s; i++) {
			cout << ans[i] << ' ';
		}
	}
	return res;
}
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll a, b, w, p;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> w >> p;
		edges[i] = {i, a, b, w, p};
	}
	ll t = kruskal();
	return 0;
}

