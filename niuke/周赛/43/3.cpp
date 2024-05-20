#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
string s;
ll da[N], xiao[N];
void solve()
{
	cin >> s;
	rep(i, 0, s.size() - 1)
	{
		if (s[i] >= 'a' && s[i] <= 'z') xiao[i] = 1;
		else da[i] = 1;
	}
	rep(i, 1, s.size() - 1)
	{
		xiao[i] += xiao[i - 1];
		da[i] += da[i - 1];
	}
	ll minn = INF;
	rep(i, 0, s.size() - 2)
	{
		ll t = xiao[i] + da[s.size() - 1] - da[i];
//		cout<<t<<"-";
		minn = min(t, minn);
	}
	cout << minn << "\n";
	return ;
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
