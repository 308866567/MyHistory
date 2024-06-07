#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll arr[N];
ll s[N];
void solve()
{
	cin >> n;
	if (n == 1)
	{
		cout << 0 << "\n";
		return;
	}
	ll sum = 0;
	rep(i, 1, n)
	{
		cin >> arr[i];
		sum += arr[i];
		s[i]=sum;
	}
	ll ans = 0;
	ll l = 0;
	rep(i, 1, n-1)
	{
		l += arr[i];
		ans = max(ans, abs(sum - l-l));
	}
	ll r = 0;
	rrep(i, n, 2)
	{
		r += arr[i];
		ans = max(ans, abs(sum - r-r));
	}

	rep(i,1,n){
		ll tl=s[i-1]-s[0];
		ll tr=s[n]-s[i];
		if(tl>0)
		ans=max(ans,abs(tl-arr[i]));
		if(tr>0)
		ans=max(ans,abs(tr-arr[i]));
	}
	cout << ans << "\n";
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
