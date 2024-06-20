#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll x;
void solve()
{
	cin >> n >> x;
	ll s = 0;
	bool f = 0; // 1表示打开
	if (n >= x)
	{
		ll t = sqrt(x);
		if (t * t == x)
			f = 1;
		else
			f = 0;
	}
	else
	{
		if (n == 1)
		{
			f = 1;
		}
		else
		{
			for (ll i = 1; i * i <= x; i++)
			{
				if (i * i == x)
					s++;
				else if (x % i == 0)
				{
					if (x / i <= n)
						s += 2;
					else
						s++;
				}
			}
			f = s & 1;
		}
	}
	if (f)
		cout << "ON\n";
	else
		cout << "OFF\n";
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
