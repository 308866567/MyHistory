#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll a[10], k;
ll f[10];
ll cal(ll x, ll y)
{
	rep(i, 0, 10)
	{
		if (i != x && i != y)
			return i;
	}
}
ll solve()
{
	ll s0 = 0;
	ll s1 = 0;
	ll s2 = 0;
	ll s3 = 0;
	rep(i, 1, 3)
	{
		cin >> a[i];
		f[a[i]] = 1;
		if (a[i] == 0)
			s0++;
		if (a[i] == 1)
			s1++;
		if (a[i] == 2)
			s2++;
		if (a[i] > 2)
			s3++;
	}
	cin >> k;
	ll ans = 0;
	if (f[k] > 0)
	{
		return ans;
	}
	if (k > 2)
		return -1;
	if (k == 0)
	{
		// 没有0
		return 1;
	}
	else if (k == 1)
	{
		// 没有1
		// 先造0,再造1
		if (s0 == 1)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (k == 2)
	{
		// 没有2
		// 0,1,2
		ans = 3;
		if (s0 > 0)
			ans--;
		if (s1 > 0)
			ans--;
		return ans;
	}
	return ans;
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
	cin >> t;
	while (t--)
	{
		cout << solve() << "\n";
	}
	return 0;
}
