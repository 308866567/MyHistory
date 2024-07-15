#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll sum = 0;
ll read()
{
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
	{
		sum += ch - '0';
		sum %= 3;
		ch = getchar();
	}
	return 0;
}
void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		read();
	}
	if (sum % 3 == 0)
	{
		cout << "YES\n";
	}
	else
		cout << "NO\n";
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
