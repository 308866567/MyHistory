#include <iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e4 + 1;
unordered_map<ll, unordered_map<ll, ll>> g;
ll w[N];
ll dp[N][2];  //dp[i][1]��ʾ���ڵ�iȥ
bool u[N];
//���ڵ㲻ȥʱ,Ϊ�ӽڵ�Ĺ���
//dp[i][0]=sum(max(dp[son][1],dp[son][0]));
//���ڵ�ȥʱ,Ϊ�ӽڵ㲻ȥʱ�Ĺ��׼Ӹ��ڵ�Ĺ���
//dp[i][1]=sum(dp[son][0])+happy[i];
ll n;
void dfs(ll u, ll father)
{
//	cout<<u<<' ';
	//��ʼ��
	dp[u][1] = w[u];
	dp[u][0] = 0;
	ll v;
	for (auto it : g[u])
	{
		v = it.first;
		if (v == father)
			continue;
		dfs(v, u);
		//ת��
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
	//dp[u][0]=
	return ;
}
void out(ll *x)
{
	for (int i = 0; i <= 1; i++)
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
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	ll l, k;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> l >> k;
		g[k][l] = 1;//���򽨱�
		u[l] = 1;
//		g[l][k] = 1;
	}
	//���ҳ�Ψһ�ĸ�,���ڵ�ֻ�г���,û�����
	ll root = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!u[i])
		{
			root = i;
			break;
		}
	}
//	cout << root << '\n';
	dfs(root, -1);
//	for (int i = 1; i <= n; i++)
//	{
//		out(dp[i]);
//	}
	cout<<max(dp[root][1],dp[root][0])<<"\n";
	return 0;
}
