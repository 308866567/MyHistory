#include <iostream>
using namespace std;
typedef long long ll;
const int N=1002;
ll g[N][N];
ll dp[N][N]= {0}; //从该点出发不使用到终点所能获得的最大宝藏数
ll dp2[N][N]= {0}; //从起点到该点的max
ll n,m;//行,列
void d1(int i,int j) {
	if(i==n&&j==m)
		dp[i][j]=g[i][j];
	else if(i==n)//下面没路
		dp[i][j]=g[i][j]+dp[i][j+1];
	else if(j==m)//右面没路
		dp[i][j]=g[i][j]+dp[i+1][j];
	else
		dp[i][j]=g[i][j]+max(dp[i+1][j],dp[i][j+1]);
}
void d2(int i,int j) {
	if(i==1&&j==1)
		dp2[i][j]=g[i][j];
	else if(i==1)//上面没路
		dp2[i][j]=g[i][j]+dp2[i][j-1];
	else if(j==1)//左面没路
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

	//处理dp数组
	for(int i=n; i>0; i--) {
		for(int j=m; j>0; j--) {
			d1(i,j);
			d2(n-i+1,m-j+1);//1,1开始
		}
	}


	//输出
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
	//选择两个传送门加上
	ll t,k,gate[6][2]= {0};
	cin>>t;
	while(t--) {
		cin>>k;
		sum=-1e10;
		for(int i=1; i<=k; i++)
			cin>>gate[i][0]>>gate[i][1];

		//5个传送门,两两组合
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=k; j++) {
				if(i==j)//通过这个传送门到达其它任意一个具有传送门的位置
					continue;


				t1=dp2[gate[i][0]][gate[i][1]];//先到i传送门
				t2=dp[gate[j][0]][gate[j][1]];//从j传送门出来
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
