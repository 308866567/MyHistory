#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 5;
vector<vector<ll>> g;
ll n;
ll sum[N];

ll s1[N];//�ӽڵ�Ĺ���
ll size1[N];//�ӽڵ����
void dfs(ll u, ll father)
{
	size1[u] = 1; //����ʱ��ȼ��ٰ�������
	for (ll i : g[u])
	{
		if (i == father)
			continue;
		dfs(i, u);
		size1[u] += size1[i];
		s1[u] += s1[i] + size1[i] ; //�ӽڵ���Ⱥ�+����Ϊ���ڵ�Ĺ���
	}
	return ;
}
void dfs2(ll u, ll father)
{
	for (ll i : g[u])
	{
		if (i == father)
			continue;
		s1[i] = s1[u] + n - 2 * size1[i]; //���������ȱ仯
		dfs2(i, u);
	}
	return ;
}
void out(ll *x)
{
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << ' ';
	}
	cout << "\n";
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n + 2);
	ll u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
//	out(s1);
//	out(size1);
	dfs2(1, -1);
//	out(s1);

	ll maxx = 1;
	for (int i = 1; i <= n; i++)
	{
		if (s1[i] > s1[maxx]) maxx = i;
	}
	cout << maxx;
	return 0;
}
