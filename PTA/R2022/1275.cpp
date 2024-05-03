#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 25 + 5;
ll m, p;//最多有2e5个数
ll n = 0;//当前序列的个数
class segmentTree//维护区间最大值
{
	public:
		struct node
		{
//			ll val;//节点值,区间和
			ll l=-1, r=-1;//代表区间[l,r]
			ll maxx = -1; //区间最大值
		} t[4 * N];
		ll *a;//原数组
		inline ll ls(ll p)//左子节点位置
		{
			return p << 1;//*2
		}
		inline ll rs(ll p)//右子节点位置
		{
			return p << 1 | 1;//*2+1
		}
		void push_up(ll p)//由子节点更新父节点p
		{
			t[p].maxx = max(t[p].maxx, max(t[ls(p)].maxx, t[rs(p)].maxx));
		}
		//标记实现区间修改
		void push_down(ll p)
		{

		}
		//查询区间内的最大值
		ll query( ll tl, ll tr, ll p, ll l, ll r  )
		{
			push_up(p);//更新当前节点
			if (l >= tl && r <= tr)
			{
				return t[p].maxx;
			}
			ll res = -1;
			ll mid = (l + r) / 2;
			//取最大
			if (mid >= tl)
				res = query(tl, tr, ls(p), l, mid);
			if (mid < tr)
				res = max(res, query(tl, tr, rs(p), mid + 1, r));
			return res;
		}
		//单点修改
		void update( ll tl, ll tr, ll k, ll p, ll l, ll r  )
		{
			if (l >= tl && r <= tr)
			{
				t[p].maxx = max(k, t[p].maxx);
				return;
			}
			ll mid = (l + r) / 2;
			//递归子节点
			if (mid >= tl)
				update(tl, tr, k, ls(p), l, mid);
			if (mid < tr)
				update(tl, tr, k, rs(p), mid + 1, r);
			push_up(p);
			return ;
		}
		void build(ll p, ll l, ll r)
		{
			t[p].l = l;
			t[p].r = r;
			if (l == r)
			{
				return;
			}
			ll mid = (l + r) / 2;
			build(ls(p), l, mid);
			build(rs(p), mid + 1, r);
		}
};
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> p;
	char t1;
	ll t2;
	ll a = 0;
	segmentTree T;
//	T.build(0, 1, 1, n);
	T.build(1,1,m);
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		if (t1 == 'A')//添加操作
		{
			t2 = (t2  + a) % p;
			//添加t2到末尾
			n++;
			T.update(n, n, t2, 1, 1, m);
		}
		else//查询操作
		{
//			cout<<n-t2+1<<" "<<n<<":";
			a = T.query(n - t2 + 1, n, 1, 1, m);
			cout << a << "\n";
		}
		//7029
	}
	return 0;
}
