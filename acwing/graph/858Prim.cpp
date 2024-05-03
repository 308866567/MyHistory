#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef int ll;
const ll N = 510,INF=0x3f3f3f3f;
ll n,m;
ll g[N][N];
ll dist[N];//dist[i] ��ʾ i �ڵ㵽��ͨ���ֵ���̾��롣
bool st[N];//��ת�ڵ�
//
ll prim()//������С�������ı�Ȩ��
{	
	memset(dist,INF,sizeof dist);
	ll res=0;
	for(int i=0;i<=n;i++)
	{
		int t=-1;
		for(int j=1;j<=n;j++)//ѡȡһ������ͨ��������Ľڵ�
		{
			if(!st[j]&&(t==-1||dist[t]>dist[j]))
				t=j;
		}
		if(i&&dist[t]==INF) //�޷���ͨ
			return INF;
		if(i)//i>0ʱ 
			res+=dist[t];
		st[t]=1;
		for(int j=1;j<=n;j++)//i=0ʱ,����ͨt�����Ľڵ�
		{
			dist[j]=min(dist[j],g[t][j]);//i>0ʱ,��������ͨ���ֵľ���
		}
	}
	return res;
}
int main()
{ 
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	memset(g,INF,sizeof g);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ll a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=min(g[a][b],c);
	}
	ll t=prim();
	if(t==INF) cout<<("impossible");
	else cout<<t;
	return 0;
}
