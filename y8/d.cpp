#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll L, R;
ll h[N];
void solve()
{
	cin >> n >> L >> R;
	rep(i, 1, n)
	{
		cin >> h[i];
	}
	ll l = 1, r = 1;
	ll sum = h[1];
	ll ans = 0;
	if(h[1]>=L&&h[1]<=R) 
		ans++;
	while (r <= n)
	{
		//以当前l为起点,满足条件的区间
		while (r <= n && sum >= L && sum <= R)
		{
			r++;
			sum += h[r];
		}
		cout << l << "---" << r << "\n";
		ans += r - l;
		//找新起点
		sum -= h[l];
		l++;
		//不在区间内就继续找
		while (l <= n && sum < L && sum > R)
		{
			sum -= h[l];
			l++;
		}
		cout << l << "---" << r << "\n";
//		ans += r - l;
		cout << "\n";
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
