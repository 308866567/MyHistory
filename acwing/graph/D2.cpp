#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<queue>
typedef long long ll;
const ll N = 2e5;
using namespace std;
unordered_map<int, unordered_map<int, int>>g;//�ڽӱ�
ll dist[N];
int n, m;
int x, y, z;
bool st[N];
struct node
{
	ll v, w; //�յ�,����
	node(ll a, ll b)
	{
		v = a;
		w = b;
	}
	bool operator<(const node &x) const
	{
		return w > x.w;
	}
};
ll dijkstra()
{
	priority_queue <node> q;
	memset(dist, 0x3f, sizeof(dist));//����Сֵ,��ʼ��Ϊ������
	dist[1] = 0; //���Ϊ0
	q.push(node(1, 0));
	while (!q.empty())
	{
		node h = q.top(); //t.u�ǵ�ǰ��������ĵ�
		q.pop();
		ll t = h.v;
		if (st[t]) continue;
		st[t] = 1;
		dist[t] = h.w;
		//��tΪ��ת����t�ĺ��
		for (auto it : g[t])
		{
			int j = it.first;
			if (dist[j] > dist[t] + g[t][j])
			{
				dist[j] = dist[t] + g[t][j];
				q.push(node(j, dist[j]));
			}
		}
		
	}
	if (dist[n] >= 1e9)
		return -1;
	return dist[n];
}
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		if (g[x][y] == 0)
			g[x][y] = z;
		else
			g[x][y] = min(g[x][y], z);
	}
	cout << 	dijkstra();
	
	return 0;
}
