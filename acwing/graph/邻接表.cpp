#include <iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 1;
//e,w�洢�յ��Ȩֵ,������idx
//ne�洢ͬ�����һ���ߵ�����
//h[a]�洢���a���һ���ߵ�����
//h��Ҫ��ʼ��Ϊ-1
ll h[N], w[N], e[N], ne[N], idx;
void add(ll a, ll b, ll c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a];
	h[a] = idx++;
}
//dfs
bool st[N];
void dfs(ll u)
{
	st[u] = 1;
	for (int i = h[u]; i != -1; i = ne[i])//i�Ǳ�����
	{
		int j = e[i]; //�յ�
		if (st[j])
			continue;
		dfs(j);
	}
	return ;
}
//bfs
#include<queue>
void bfs()
{
	int d[N];//�洢�ڵ�Ĳ��
	memset(d, -1, sizeof d);
	queue<int> q;
	d[1] = 0;//���ڵ�Ϊ��0��
	q.push(1);

	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)//��ֹ�ظ�����
			{
				d[j] = d[t] + 1;
				q.push(j);
			}
		}
	}
}
int main()
{
	//freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll n, m;
	cin >> n >> m;
	//m����
	ll a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		add(a, b, c);//�����a->b
	}
	return 0;
}
