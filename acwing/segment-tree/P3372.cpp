#include <iostream>
typedef long long ll;
const ll N = 1e5 + 5;
using namespace std;
ll n, m;
ll arr[N];
class segmentTree
{
public:
	struct node
	{
		ll val = 0;
		ll lazy = 0;
	} t[4 * N];
	inline ll ls(ll p)
	{
		return p << 1;
	}
	inline ll rs(ll p)
	{
		return p << 1 | 1;
	}
	ll *a;				 // 原始数组
	void push_down(ll p,ll l,ll r) // 更新子节点
	{
		if (t[p].lazy == 0)
			return;
		ll mid=(l+r)>>1;
		t[ls(p)].val += t[p].lazy*(mid-l+1);
		t[rs(p)].val += t[p].lazy*(r-mid);
		t[ls(p)].lazy += t[p].lazy;
		t[rs(p)].lazy += t[p].lazy;
		t[p].lazy = 0;
	}
	void push_up(ll p)
	{
		t[p].val = t[ls(p)].val + t[rs(p)].val;
	}
	
	segmentTree(ll *x)
	{
		a = x;
		build();
	}
	void build(ll p = 1, ll l = 1, ll r = n)
	{
		if (l == r)
		{
			t[p].val = a[l];
			return;
		}
		ll mid = (l + r) >> 1;
		build(ls(p), l, mid);
		build(rs(p), mid + 1, r);
		push_up(p);
	}
	void update(ll tl, ll tr, ll d, ll p = 1, ll l = 1, ll r = n)
	{
		if (l >= tl && r <= tr)
		{
			t[p].val += (r - l + 1) * d;
			t[p].lazy += d;
			return;
		}
		push_down(p,l,r);
		ll mid = (l + r) >> 1;
		if (mid >= tl)
			update(tl, tr, d, ls(p), l, mid);
		if (mid < tr)
			update(tl, tr, d, rs(p), mid + 1, r);
		push_up(p);
	}
	ll query(ll tl, ll tr, ll p = 1, ll l = 1, ll r = n)
	{
		if (l >= tl && r <= tr)
		{
			return t[p].val;
		}
		push_down(p,l,r);
		ll res = 0;
		ll mid = (l + r) >> 1;
		if (mid >= tl)
			res += query(tl, tr, ls(p), l, mid);
		if (mid < tr)
			res += query(tl, tr, rs(p), mid + 1, r);
		return res;
	}
	void out()
	{
		for (int i = 1; i <= n; i++)
		{
			cout << query(i,i) << ' ';
		}
		cout << "\n";
	}
};

int main()
{
	//		freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	segmentTree A(arr);
	ll x;
	ll t;
	ll tl, tr, k;
	while (m--)
	{
		cin >> t;
		switch (t)
		{
			case 1: // 加上k
			//							x = A.query(1, n);
			//							cout << "old:" << x << "\n";
			cin >> tl >> tr >> k;
			A.update(tl, tr, k);
			//							x = A.query(1, n);
			//							cout << "new:" << x << "\n\n";
			break;
			case 2: // 查询
			cin >> tl >> tr;
			x = A.query(tl, tr);
			cout << x << "\n";
			break;
		}
	}
	return 0;
}
