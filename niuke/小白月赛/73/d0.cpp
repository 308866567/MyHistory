#include <iostream>
typedef long long ll;
const ll N = 2e5+3;
using namespace std;
ll dp[N];
ll dp0[N];//科学计数法
ll t;
ll n,k;
ll ans=0;
ll f(ll x)//返回x的末尾0个数
{
	ll s=0;
	while(x%10==0)
	{
		x/=10;
		s++;
	}
	return s;
}
//计算一个数=x*2^i*5^j
//前缀乘时舍弃x
//求i,j
ll f1(ll x){
	
}
//dp[i][j]表示i-j前缀乘的0的个数
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>dp[i];
		}
		for(int i=n;i>0;i--){
			for(int j=n;j>=i;j--)
			{
				if(i!=j)
					dp[j]*=dp[i];//更新dp[j]
				//统计0
				if(f(dp[j])==k)
					ans++;
			}
						for(int k=1;k<=n;k++){
							cout<<dp[k]<<' ';
						}
						cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
