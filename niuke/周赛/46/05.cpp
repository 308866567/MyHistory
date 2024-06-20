#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
struct node
{
	ll a, b;
	bool operator<(const node &t) const
	{
		return b < t.b;
	}
} a[N];
ll s[N];
ll ss[N];
ll n;
ll q, k;
void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		cin >> a[i].a;
	}
	rep(i, 1, n)
	{
		cin >> a[i].b;
	}
	sort(a + 1, a + 1 + n);
	rep(i, 1, n)
	{
		s[i] = s[i - 1] + a[i].a * a[i].b;
		ss[i]=s[i-1]+a[i].a;
	}
	cin >> q;
	rep(i, 1, q)
	{
		cin >> k;
		ll t = upper_bound(a + 1, a + 1 + n, node{0, k}) - a;
		ll ans = s[t-1];
		ans+=k*(ss[n]-ss[t-1]);
		cout << ans << "\n";
	}
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
