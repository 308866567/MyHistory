#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;

void solve()
{
	ll n;
	cin>>n;
	string s;
	string R;
	unordered_map<char,char> g;
	bool v[30];
	memset(v, 0, sizeof v);
	cin >> s;
	for (char t : s)
	{
		v[t - 'a'] = 1;
	}
	rep(i, 0, 28)
	{
		if (v[i])
		{
			R += 'a' + i;
		}
	}
	ll l = 0, r = R.size() - 1;
	while (l <= r)
	{
		g[R[l]]=R[r];
		g[R[r]]=R[l];
		l++,r--;
	}
	for (char t : s)
	{
		cout<<g[t];
	}
	cout<<"\n";
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
		solve();
	}
	return 0;
}
