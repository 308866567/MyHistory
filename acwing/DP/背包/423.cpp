#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll m;
ll t[N], w[N]; // 时间,价值
ll dp[N];
ll n; // 总时间
void solve()
{
	cin >> n >> m;
	rep(i, 1, m)
	{
		cin>>t[i]>>w[i];
	}
	//只能采一次,01背包
	rep(i,1,m){
		//时间
		//一维数组倒序,防止后效性
		rrep(j,n,1){
			if(j>=t[i])
			dp[j]=max(dp[j],dp[j-t[i]]+w[i]);		}
	}
	cout<<dp[n]<<"\n";
}

int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
	freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
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
