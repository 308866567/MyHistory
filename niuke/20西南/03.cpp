#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e3 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
typedef pair<ll, ll> pii;
ll n, m, q;
class segmentTree
{
public:
	struct node
	{
		ll sum = 0; // 区间能量和8
		//			int minn = 0;
		//			int l, r;
		ll mark = 0;
	} t[4 * N];
	segmentTree() {}
	inline ll ls(ll p)
	{
		return p << 1;
	}
	inline ll rs(ll p)
	{
		return p << 1 | 1;
	}
	inline void push_up(ll p)
	{
		t[p].sum = t[ls(p)].sum + t[rs(p)].sum;
	}
	inline void push_down(ll p, ll l, ll r)
	{
		if (t[p].mark == 0)
			return;
		ll mid = (l + r) / 2;
		t[ls(p)].sum += t[p].mark * (mid - l + 1);
		t[rs(p)].sum += t[p].mark * (r - mid);
		t[ls(p)].mark += t[p].mark;
		t[rs(p)].mark += t[p].mark;
		t[p].mark = 0;
	}
	// 区间修改
	void update(ll tl, ll tr, ll k, ll p = 1, ll l = 1, ll r = n)
	{
		if (l >= tl && r <= tr)
		{
			t[p].sum += k * (r - l + 1);
			t[p].mark += k;
			return;
		}
		push_down(p, l, r);
		ll mid = (l + r) / 2;
		if (mid >= tl)
		{
			update(tl, tr, k, ls(p), l, mid);
		}
		if (mid < tr)
		{
			update(tl, tr, k, rs(p), mid + 1, r);
		}
		push_up(p);
		return;
	}
	// 区间和查询
	ll query(ll tl, ll tr, ll p = 1, ll l = 1, ll r = n)
	{
		if (l >= tl && r <= tr)
		{
			return t[p].sum;
		}
		push_down(p, l, r);
		ll sum = 0;
		ll mid = (l + r) / 2;
		if (mid >= tl)
		{
			sum += query(tl, tr, ls(p), l, mid);
		}
		if (mid < tr)
		{
			sum += query(tl, tr, rs(p), mid + 1, r);
		}
		return sum;
	}
};

ll a[N];
ll v[N];
map<ll, ll> c;

void solve()
{
	cin >> n >> m >> q;
	segmentTree A;
	rep(i, 1, m)
	{
		cin >> a[i];
	}
	rep(i, 1, m)
	{
		cin >> v[i];
		c[a[i]] = v[i];
	}
	auto l = c.begin();
	auto r = ++c.begin();
	for (; r != c.end(); l++, r++)
	{
		ll x = l->first, y = r->first;
		ll val = l->second * r->second;
		A.update(x, y, val);
		A.update(x, x, -val);
		A.update(y, y, -val);
	}
	// rep(i, 1, n)
	// {
	// 	cout << A.query(i, i) << " ";
	// }
	// cout << "\n";
	ll t, x, y;
	rep(i, 1, q)
	{
		cin >> t >> x >> y;
		if (t == 1)
		{
			c[x]=y;
			auto t = c.lower_bound(x);
			auto R = ++t;
			--t;
			auto L = --t;
			t++;
			ll vl = L->second;
			ll vr = R->second;
			A.update(L->first, x, vl * (y-vr));
			A.update(x, R->first, vr * (y-vl));
			// 点清0
			A.update(L->first, L->first, -A.query(L->first, L->first));
			A.update(t->first, t->first, -A.query(t->first, t->first));
			A.update(R->first, R->first, -A.query(R->first, R->first));
			// rep(i, 1, n)
			// {
			// 	cout << A.query(i, i) << " ";
			// }
			// cout << "\n";
		}
		else
		{
			cout << A.query(x, y) << "\n";
		}
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
