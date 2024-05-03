#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long N = 1e4 + 5, M = N * 2;
int h[N], e[M], w[M], ne[M], idx;//�ڽӱ�
ll ans[N], d1[N], d2[N];
ll s1[N], s2[N];
ll n;
/*
����DP һ���Ϊ�������裺
ָ������һ�����ڵ�
һ��dfs������ͳ�Ƴ���ǰ�����ڵĽڵ�Ե�ǰ�ڵ�Ĺ���
һ��dfs������ͳ�Ƴ���ǰ�ڵ�ĸ��ڵ�Ե�ǰ�ڵ�Ĺ��ף�Ȼ��ϲ�ͳ�ƴ�
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
	ll dist = 0;//���㵱ǰ�ڵ㵽����������ڵ����Զ����ʹγ�����
	//�γ��������ڼ��㸸�ڵ�Ĺ���
	for (int i = h[u]; i != -1; i = ne[i])
	{
		ll j = e[i];
		if (j == father)
			continue;
		dist = dfs(j, u) + w[i];
		if (dist >= d1[u])
		{
			s2[u] = s1[u];
			s1[u] = j;//u�ڵ���·���ϵ���һ���ڵ�
			d2[u] = d1[u];
			d1[u] = dist;//u�ڵ�Ĵγ�·���ϵ���һ���ڵ�
		}
		else if (dist > d2[u])
		{
			d2[u] = dist;
			s2[u] = j;
		}
	}
	return d1[u];
}
ll dfs2(int u, int father) //���ڵ㵽��ǰ�ڵ�ľ���
{
	//1��ǰ�ڵ�����һ���ڵ���·����ʱ
	//2�����·����ʱ
	for (int i = h[u]; i != -1; i = ne[i])
	{
		ll j = e[i];
		if (j == father)
			continue;
		//�ȸ����ӽڵ�j,���������ӽڵ�ʱ,���ڵ�Ĺ����Ѿ�֪����
		if (j == s1[u])//j���·����
		{
			ans[j] = w[i] + max(ans[u], d2[u]); //���ڵ�Ĵγ����߸��ڵ�ĸ��ڵ�·��
		}
		else
		{
			ans[j] = w[i] + max(ans[u], d1[u]); //���ڵ������߸��ڵ�ĸ��ڵ�·��
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
//�㵽��������������Զ������Է�Ϊ
//max(�����ӽڵ��·��-������,�������ڵ��·��-������)
//���ڵ�Ĺ����Ǹ��ڵ��а����ӽڵ��·�������γ�
//���γ��ĵ�һ������ͬ?
//�ڽӱ�֤��ʹγ�·������ʼ�ӽڵ�һ����ͬ
//������n���ڵ�ȡmin
