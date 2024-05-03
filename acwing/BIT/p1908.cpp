#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long N = 1000;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
class Bit
{
#define lowbit(x) x&(-x)
	public:
		ll n;
		ll *arr;
		struct node
		{
			ll s;
		} tree[N];
		void update(ll x, ll k)//�����޸�
		{
			for (ll i = x; i <= n; i += lowbit(i))
			{
				tree[i].s += k;
			}
		}
		ll query(ll x)//�����ѯ
		{
			ll sum = 0;
			for (ll i = x; i > 0; i -= lowbit(i))
			{
				sum += tree[i].s;
			}
			return sum;
		}
		void cal()
		{
			memset(tree, 0, sizeof (tree));
			ll ans = 0;
			for (int i = 1; i <= n; i++)
			{
				update(arr[i], 1);
				ans += i - query(arr[i]); //���������ڵ�����
//			 cout<<ans<<"\n";
			}
			cout << ans << "\n";
		}
};
//
struct node
{
	ll w;
	ll i;
	bool operator<(node &b)
	{
		if (w == b.w)
			return i < b.i;
		return w < b.w;
	}
} t[N];
ll arr[N];//��ɢ���������
int main()
{
//	fre;
	fast;
	Bit B;
	cin >> B.n;
	for (int i = 1; i <= B.n; i++)
	{
		cin >> t[i].w;
		t[i].i = i;
	}
	//��ɢ��,����ԭ�����ֵ�������±�����
	sort(t + 1, t + 1 + B.n);
	for (int i = 1; i <= B.n; i++)
	{
		arr[t[i].i] = i;
	}
	B.arr = arr;
	B.cal();
	return 0;
}
