#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 10;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//将数组升序排序(升序采用大顶堆，降序采用小顶堆)
ll n, m;
class heap
{
public:
		ll a[N];
		ll R;//堆的右边界
		void slove()
		{
			R = n;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			//从第一个非叶节点开始，从右到左，从下到上处理每个节点
			for (int i = n >> 1; i >= 1; i--)
			{
				down(i);
			}
			while (m--)
			{
				cout << a[1] << ' ';
				swap(a[1], a[R]);
				R--;
				down(1);
			}
		}
		void down(ll u)
		{
			ll t = u;
			ll l = u << 1, r = u << 1 | 1;
			//有左儿子,且左儿子比t小,更新
			if (l <= R && a[l] < a[u])
				t = l;
			//有右儿子,且右儿子比t小,更新
			if (r <= R && a[r] < a[t])
				t = r;
			//如果待调整点不是最小的
			if (u != t)
			{
				swap(a[u], a[t]);
				down(t);
			}
		}
};
int main()
{
//	fre;
	fast;
	cin >> n >> m;
	heap H;
	H.slove();
	return 0;
}
