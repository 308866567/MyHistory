#include <iostream>
typedef long long ll;
const ll N = 2e5+3;
using namespace std;
ll dp[N];
ll dp0[N];//��ѧ������
ll t;
ll n,k;
ll ans=0;
ll f(ll x)//����x��ĩβ0����
{
	ll s=0;
	while(x%10==0)
	{
		x/=10;
		s++;
	}
	return s;
}
//����һ����=x*2^i*5^j
//ǰ׺��ʱ����x
//��i,j
ll f1(ll x){
	
}
//dp[i][j]��ʾi-jǰ׺�˵�0�ĸ���
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
					dp[j]*=dp[i];//����dp[j]
				//ͳ��0
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
