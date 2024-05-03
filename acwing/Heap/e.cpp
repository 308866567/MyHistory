#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e5+10;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//题目中位数取floor(len/2)+1
//所以中位数x满足有len/2个>=x
ll arr[N];//原数组
ll sum[N];
ll temp[N];
ll n;
ll s = 0;
void merge(ll b, ll e, ll *nums, ll *temp)
{
	for (int i = b; i <= e; i++)
	{
		temp[i] = nums[i];
	}
	ll l = b, mid = (b + e) >> 1, r = mid + 1;
	for (int p = b; p <= e; p++)
	{
		if (l > mid)
		{
			nums[p] = temp[r++];
		}
		else if (r > e)
		{
			nums[p] = temp[l++];
		}
		else if (temp[l] > temp[r])
		{
			nums[p] = temp[l++];
		}
		else//逆序对位置*r>=*(l-1)
		{
			nums[p] = temp[r++];
			s += mid - l + 1;
		}
	}
}
void msort(ll b, ll e, ll *nums)
{
	if (b == e) return ;
	ll mid = (b + e) >> 1;
	msort(b, mid, nums);
	msort(mid + 1, e, nums);
	merge(b, e, nums, temp);
}
ll aim ;
bool check(ll x)//x是中位数需要满足有len/2个>=x
{
	//计算有多少个区间，他的中位数>=x
	//接着通过求区间和来判断，区间和>=len*x的话，他的中位数肯定>=x
	//通过离散化来求区间和
	//求区间和用前缀和来求
	//sum[r]-sum[l-1]>=0等价sum[r]>=sum[l-1](r>l-1)
	//求逆序对个数
	sum[0]=0;
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] >= x)
			sum[i] = 1;
		else
			sum[i] = -1;
		sum[i] += sum[i - 1];
		if(sum[i]>=0) s++;
	}
	msort(1, n, sum);
//	cout<<x<<"-"<<s<<"\n";
	if (s >= aim)
	{
		return 1;
	}
	else return 0;
}
int main()
{
//	fre;
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	aim = (1LL + n) * n / 2;//区间个数
	aim=(aim + 1) / 2;
	//二分枚举中位数的中位数x
	ll l = 1, r = 1e9+10, mid;
	while (l < r) // 右侧
	{
		mid = (l + r) >> 1;
		if (check(mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	cout << l-1;
	return 0;
}
