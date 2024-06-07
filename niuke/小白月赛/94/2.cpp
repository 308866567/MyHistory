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
ll b[N];
void solve()
{
	cin >> n;
	ll ans=0;
	rep(i, 1, n)
	{
		cin >> arr[i];
		if(i!=1&&arr[i]>arr[i-1]) 
			ans=n;
	}
	if (n == 1)
	{
		cout << 0 << "\n";
		return;
	}
	cout<<ans<<"\n";
	//最长不升序数组长度
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
