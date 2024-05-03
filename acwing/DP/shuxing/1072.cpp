#include <iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const long long N = 1e4 + 5, M = N * 2;
//�����·��,Ҳ��Ϊֱ��
//״̬��ʾ-����
//�Խڵ�iΪ����������,������ĳ���ڵ㵽i���·Ϊf1[i],�γ�·Ϊf2[i]
int h[N], e[M], w[M], ne[M], idx;//�ڽӱ�
ll ans;
ll n;
ll a, b, c;
inline void add(int a, int b, int c)
{
	e[idx] = b;//��ǰ���յ�
	w[idx] = c;//��ǰ��Ȩֵ
	ne[idx] = h[a];//�ڽӱ���һ���ڵ�����
	h[a] = idx++;
}
ll dfs(int u, int father)
{
//	cout<<u<<' ';
	ll dist = 0;//�·��
	ll d1 = 0, d2 = 0;//�·���ʹγ�·��
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j == father)
			continue;//��ֹ��ѭ��
		ll d = dfs(j, u) + w[i]; //�ӽڵ���·��
		dist = max(dist, d);
		if (d >= d1)
		{
			d2 = d1;
			d1 = d;
		}
		else if (d > d2) d2 = d;
	}
	//�·��Ϊ���ڵ���������Ӵγ�
	ans = max(ans, d1 + d2); //ÿ���ڵ㶼Ҫ�ж�һ�δ�
	return dist;//�����·��
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




