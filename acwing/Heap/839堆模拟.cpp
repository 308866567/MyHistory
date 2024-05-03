#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e5+87;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
ll n, m;//m代表第几个插入的元素
class heap
{
#define ls u<<1
#define rs ((u<<1)|1)
public:
	ll h[N], ph[N], hp[N], cnt=0;
	//ph（point->heap）可以获得第几个插入的元素现在在堆的那个位置
	//hp(heap->point)可以获得在堆的第n个元素存的是第几个插入的元素
	//h 堆位置-值
	//hp 堆位置-第几个插入
	//ph 第几个插入-堆位置
	void heap_swap(ll a, ll b)
	{
		swap(ph[hp[a]], ph[hp[b]]);
		swap(hp[a], hp[b]);
		swap(h[a], h[b]);//节点值交换
	}
	void down(ll u)//下沉u
	{
		
		ll t = u;//t点为3个点的最小值
		if (ls <= cnt && h[ls] < h[t]) t = ls;
		if (rs <= cnt && h[rs] < h[t]) t = rs;
		if (u != t)//根不是min,下沉
		{
			heap_swap(u, t);
			down(t);
		}
	}
	void up(ll u)//新元素都是在堆尾,调整到顶
	{
		while (u / 2 && h[u] < h[u / 2])//小于父节点就交换
		{
			heap_swap(u, u / 2);
			u >>= 1;
		}
	}
	void slove()
	{
		string op;
		ll k, x;
		while (n--)
		{
			cin >> op;
			if (op == "I")//插入
			{
				cin >> x;
				cnt++, m++;
				ph[m] = cnt;
				hp[cnt] = m;
				h[cnt] = x;
				up(cnt);
			}
			else if (op == "PM")
			{
				cout << h[1]<<"\n";
			}
			else if (op == "DM")
			{
				heap_swap(1, cnt);
				cnt--;
				down(1);
			}
			else if (op == "D")
			{
				cin >> k;
				k = ph[k];
				heap_swap(k, cnt);//末尾元素代替k的位置
				cnt--;
				down(k);
				up(k);
			}
			else
			{
				cin >> k >> x;
				k = ph[k];
				h[k] = x;
				down(k);
				up(k);
			}
		}
		return;
	}
};
int main()
{
	//	fre;
	fast;
	cin >> n ;
	heap H;
	H.slove();
	return 0;
}
