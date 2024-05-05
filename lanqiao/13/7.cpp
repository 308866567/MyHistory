#include <bits/stdc++.h>
using namespace std;
typedef long  ll;
const ll N = 1e7 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
#define mod 1000000007

ll dp[N][3];//0表示上面一行1个 1表示2个 2表示下面一行1个

void slove()
{
	ll n;
	cin >> n;
	dp[1][1]=1;
	dp[2][2]=1;
	dp[2][0]=1;
	dp[2][1]=2;
	rep(i,3,n){
		dp[i][0]=(dp[i-1][2]+dp[i-2][1])%mod;
		dp[i][2]=(dp[i-1][0]+dp[i-2][1])%mod;
		dp[i][1]=((dp[i-1][0]+dp[i-1][2])%mod+(dp[i-2][1]+dp[i-1][1])%mod)%mod;
	}
	cout<<dp[n][1];
	return;
}
int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/Downloads/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		slove();
	}
	return 0;
}
//快读
inline int read() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x * f;
}
