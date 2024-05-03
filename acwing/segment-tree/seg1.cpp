#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 1;
ll n, m;
ll a[N];
class segmentTree
{
public:
	ll t[4 * N] = {0}; //存储区间和
	ll *a;//数组
	ll mark[4 * N] = {0};
	
	//返回左孩子下标
	inline ll ls(ll p)
	{
		return p << 1;//*2
	}
	
	//返回右孩子下标
	inline ll rs(ll p)
	{
		return p << 1 | 1;//*2+1
	}
	
	//回溯时向上维护区间,更新区间和
	void push_up(ll p)
	{
		t[p] = t[ls(p)] + t[rs(p)];//左右孩子的和
	}
	
	//递归时向下维护标记,父节点不用更新,因为父节点已经更新过了
	//查询时会清除mark
	void push_down(ll p, ll l, ll r)
	{
		//清除当前节点的懒标记,给叶子节点添加
		if (mark[p] == 0) //标记为0
			return ;
		ll mid = (l + r) >> 1;
		//			cout<<mark[p] * (mid - l + 1)<<" "<<mark[p] * (r - mid)<<" "<<"\n";
		t[ls(p)] += mark[p] * (mid - l + 1);//区间变化,点的个数*变化值
		t[rs(p)] += mark[p] * (r - mid);
		mark[ls(p)] += mark[p];//叶子节点加上变化值
		mark[rs(p)] += mark[p];
		mark[p] = 0;
	}
	
	
	segmentTree(ll *x)
	{
		a = x;
	}
	///递归建立,左右访问到根节点
	void build(ll p = 1, ll l = 1, ll r = n)
	{
		//p是当前所在的树节点序号,[l,r]代表其区间
		if (l == r) t[p] = a[l];
		else
		{
			ll mid = (l + r) >> 1;
			build(ls(p), l, mid);
			build(rs(p), mid + 1, r);
			push_up(p);
		}
	}
	//区间[tl,tr]每个点都加上k
	void update( ll tl, ll tr, ll k, ll p = 1, ll l = 1, ll r = n)
	{
		
		//如果当前节点代表的区间在[tl,tr]内,直接修改
		if (l >= tl && r <= tr)
		{
			mark[p] += k;
			t[p] += k * (r - l + 1);
			return ;
		}
		push_down(p, l, r);
		ll mid = (l + r) >> 1;
		//[l,mid]和[mid+1,r]两个区间
		//mid在[tl,tr]里时
		if (tl <= mid) //左半部分有可能更大些,所以=号
			update(tl, tr, k, ls(p), l, mid );
		if (tr > mid)
			update(tl, tr, k, rs(p), mid + 1, r );
		push_up(p);
		//				out();
		//cout<<"\n";
		return;
	}
	
	//区间查询
	//p为当前所在节点序号,方便得到值
	ll query( ll tl, ll tr, ll p = 1, ll l = 1, ll r = n)
	{
		ll res = 0;
		//如果当前节点代表的区间在[tl,tr]内,直接返回
		if (l >= tl && r <= tr)
		{
			return t[p];
		}
		push_down(p, l, r);
		//			push_up(p);
		ll mid = (l + r) >> 1;
		//如果[l,mid]与[tl,tr]有相交
		//左半部分起点在目标区间内
		if (tl <= mid)//左半部分有可能更大些,所以=号
			res += query(tl, tr, ls(p), l, mid );
		//如果[mid+1,r]与[tl,tr]有相交
		//右半部分起点在目标区间内
		if (tr > mid)
			res += query(tl, tr, rs(p), mid + 1, r);
		
		return res;
	}
	void out()
	{
		for (int i = 1; i <= 2 * n; i++)
		{
			cout << t[i] << ' ';
		}
		cout << "\n";
	}
};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	segmentTree A(a);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	A.build();
	ll x;
	ll t;
	ll tl, tr, k;
	while (m--)
	{
		cin >> t ;
		switch (t)
		{
			case 1://加上k
			//				x = A.query(1, n);
			//				cout << "old:" << x << "\n";
			cin >> tl >> tr >> k;
			A.update(tl, tr, k);
			//				x = A.query(1, n);
			//				cout << "new:" << x << "\n\n";
			break;
			case 2:	//查询
			cin >> tl >> tr;
			x = A.query(tl, tr) ;
			cout <<	x << "\n";
			break;
		}
	}
	return 0;
}
