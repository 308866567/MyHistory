#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e15 + 7;
ll n;
ll k[100];

bool f(ll mid)
{
	// mid为总花费
	ll sum = 0;
	rep(i, 1, n)
	{
		sum += ceil(1.0 * mid / k[i]);
		if (sum >= mid)
			return 0;
	}
	return 1;
}

void solve()
{
	cin >> n;
	ll ans = -1;
	rep(i, 1, n)
	{
		cin >> k[i];
	}
	ll l = 0, r = mod, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (f(mid))
			r=mid;
		else
			l = mid + 1;
	}
	ll t=l;
	if(t>=mod-10){
		cout<<-1<<"\n";
		return ;
	}
	rep(i, 1, n)
	{
		cout<< (ll)ceil(1.0 * mid / k[i])<<" ";
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
