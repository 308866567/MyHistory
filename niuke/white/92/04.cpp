#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n;
ll arr[N];
void solve()
{
	cin >> n;
	ll a=0,b=0,c=0;
	rep(i, 1, n)
	{
		cin >> arr[i];
		a+=arr[i];
		b-=2*i*arr[i];
		c+=i*i*arr[i];
	}
	ll ans = a+b+c;
	rep(i,1,n){ 
		ans=min(ans,a*i*i+b*i+c);
	}
	cout << ans;
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
