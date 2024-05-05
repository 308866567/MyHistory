#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n;
ll m;
ll dp[N][2];
void solve()
{
	cin >> n >> m;
	ll x, y;
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	rep(i, 1, n)
	{
		cin >> x >> y;
		rrep(j, m-1, 0)
		{
			
			dp[min(m, j+x )][0]
			=min(dp[j][0]+y,dp[min(m, j+x)][0]);
			
			dp[min(m, j+2*x  )][1]
			=min(dp[j][0]+y/2,dp[min(m, j+2*x )][1]);
			
			dp[min(m, j +x)][1]
			=min(dp[j][1]+y,dp[min(m, j+x)][1]);
		}
	}
	// rep(i,0,m){
	// 	if(dp[i][1]>0x3f3f3f) cout<<-1<<" ";
	// 	else 
	// 		cout<<dp[i][0]<<" ";
	// }
	// cout<<"\n\n";
	cout<<min(dp[m][0],dp[m][1]);
	return;
}
int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
// 快读
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
