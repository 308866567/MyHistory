#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n;
ll l[N],r[N],dp[N];
string x;
void slove()
{
	cin >> n;
	ll ans=-1;
	rep(i, 1, n)
	{
		cin >> x;
		ll a=x[0]-'0';//开头
		ll b=x[x.size()-1]-'0';//结尾
		dp[b]=max(dp[b],dp[a]+1);
		ans=max(ans,dp[b]);
	}
	cout<<n-ans;
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
