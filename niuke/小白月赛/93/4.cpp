#include <bits/stdc++.h>
#include <bitset>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
ll n, m;
ll arr[N];
void out(ll *a)
{
	rep(i, 0, (1 << n) - 1)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
}

void dfs(ll l, ll r)
{
	if (l >= r)
	{
		return;
	}
	ll mid = (l + r) >> 1;
	vector<ll> L, R;
	rep(i, 0, r - l)
	{
		if (i & 1)
		{
			R.emplace_back(arr[l + i]);
		}
		else
		{
			L.emplace_back(arr[l + i]);
		}
	}
	ll tt = l;
	for (ll t : L)
	{
		arr[tt++] = t;
	}
	for (ll t : R)
	{
		arr[tt++] = t;
	};
	dfs(l, mid);
	dfs(mid + 1, r);
}

void solve()
{
	// cin >> n >> m;
	ll R = 1 << n;
	R--;
	rep(i, 0, R)
	{
		arr[i] = i;
	}
	out(arr);
	dfs(0, R);
	out(arr);
	cout << "\n";
	cout << "\n";
}

ll reverse(ll x)
{
	ll t = n;
	string s;
	while (t--)
	{
		if (x & 1)
		{
			s += '1';
		}
		else
		{
			s += '0';
		}
		x >>= 1;
	}
	bitset<70> ans(s);
	return ans.to_ullong();
}

void solve2()
{
	cin >> n >> m;
	ll x;
	rep(i, 1, m)
	{
		cin >> x;
		cout<<reverse(x);
		cout << "\n";
	}
	
}
// r=1<<n
// mid=r/2=8
// p3=12
//  0-mid-1 i*2
//  mid-mid+mid/2-1 1<<(i-mid+1)+1
//  mid+mid/2-r-1 1<<(i-p3+2)+1
// 1000 1001
int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	n = 3;
	// cin >> t;
	while (t--)
	{
		solve2();
		n++;
	}
	return 0;
}
