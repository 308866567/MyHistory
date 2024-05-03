#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef int ll;
const long long N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
ll n, m;
ll p[N];//x�ĸ��ڵ�
struct Edge//�洢��
{
	ll a, b, w;
	bool operator <(const Edge &t)const
	{
		return w < t.w;
	}
} edges[M];
//�ж��Ƿ�������·�ķ���Ϊ��ʹ�ò��鼯
//����С��������Ϊһ������
//������ϵ�������������һ�������У�˵�����������Ѿ���ͨ�������߲�Ҫ
ll find(ll x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
ll kruskal()//����ͼ
{
	sort(edges, edges + m);
	for (int i = 1; i <= n; i++) p[i] = i;
	ll res = 0, cnt = 0;//��С������������Ȩ��֮��
	ll a, b, w;
	for (int i = 0; i < m; i++)//Ȩֵ��С����
	{
		a = edges[i].a;
		b = edges[i].b;
		w = edges[i].w;
		a = find(a), b = find(b);
		//����������֮ǰѡ������б߲�����ɻ�·����ѡ��������
		if (a != b)
		{
			p[a] = b;//a->b
			res += w;
			cnt++;
		}
	}
	//ֱ������ n ���������ͨ��ɸѡ���� n-1 ����Ϊֹ
	if (cnt < n - 1)
		return INF;
	return res;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll a, b, w;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}
	ll t = kruskal();
	if (t == INF)
		cout << "impossible";
	else
		cout << t << "\n";
	return 0;
}
