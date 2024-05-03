#include <iostream>
using namespace std;
typedef long long ll;
const int N=1002;
ll g[N][N];
ll dp[N][N]= {0}; //�Ӹõ������ʹ�õ��յ����ܻ�õ���󱦲���
ll dp2[N][N]= {0}; //����㵽�õ��max
ll n,m;//��,��
void d1(int i,int j) {
	if(i==n&&j==m)
		dp[i][j]=g[i][j];
	else if(i==n)//����û·
		dp[i][j]=g[i][j]+dp[i][j+1];
	else if(j==m)//����û·
		dp[i][j]=g[i][j]+dp[i+1][j];
	else
		dp[i][j]=g[i][j]+max(dp[i+1][j],dp[i][j+1]);
}
void d2(int i,int j) {
	if(i==1&&j==1)
		dp2[i][j]=g[i][j];
	else if(i==1)//����û·
		dp2[i][j]=g[i][j]+dp2[i][j-1];
	else if(j==1)//����û·
		dp2[i][j]=g[i][j]+dp2[i-1][j];
	else
		dp2[i][j]=g[i][j]+max(dp2[i-1][j],dp2[i][j-1]);
}
int main() {
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>g[i][j];
		}
	}

	//����dp����
	for(int i=n; i>0; i--) {
		for(int j=m; j>0; j--) {
			d1(i,j);
			d2(n-i+1,m-j+1);//1,1��ʼ
		}
	}


	//���
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout<<dp2[i][j]<<" ";
		}
		cout<<"\n";
	}


	ll ans=dp[1][1];
	ll sum=0,t1,t2;
	//ѡ�����������ż���
	ll t,k,gate[6][2]= {0};
	cin>>t;
	while(t--) {
		cin>>k;
		sum=-1e10;
		for(int i=1; i<=k; i++)
			cin>>gate[i][0]>>gate[i][1];

		//5��������,�������
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=k; j++) {
				if(i==j)//ͨ����������ŵ�����������һ�����д����ŵ�λ��
					continue;


				t1=dp2[gate[i][0]][gate[i][1]];//�ȵ�i������
				t2=dp[gate[j][0]][gate[j][1]];//��j�����ų���
				cout<<i<<" "<<j<<"   ";
				cout<<t1<<" "<<t2<<"\n";
				if(t1+t2>sum)
					sum=t1+t2;
			}
		}
		cout<<max(ans,sum)<<"\n";
	}
	return 0;
}
