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
//
ll arr[N];
ll temp[N];
ll ans = 0;
void merge(ll b, ll mid, ll e, ll *a, ll *c)
{
	for (int i = b; i <= e; i++) //辅助数组
	{
		c[i] = a[i];
	}
	ll i = b, j = mid + 1; //双指针
	for (ll p = b; p <= e; p++) //每次确定一个a[p]
	{
		if (i == mid + 1) //左半数组元素用完
		{
			a[p] = c[j++];
		}
		else if (j == e + 1)
		{
			a[p] = c[i++];
		}
		else if (c[i] <= c[j])
		{
			a[p] = c[i++];
		}
		else//右区间有元素比左区间小
		{
			a[p] = c[j++]; //从小到大,先放小的
			ans += mid - i + 1;//加上左区间长度
		}
	}
}
void msort(ll b, ll e, ll a[], ll c[]) //归并排序
{
	if (b == e)
		return;
	ll mid = (b + e) / 2;
	msort(b, mid, a, c);
	msort(mid + 1, e, a, c); //递归子区间
	//将有序数组 nums[l..mid] 和有序数组 nums[mid+1..hi]
	//合并为有序数组 nums[l..hi]
	merge(b, mid, e, a, c);
}
int main()
{
	fre;
	fast;
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	msort(1, n, arr, temp);
	cout << ans;
	return 0;
}
