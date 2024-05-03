#include <iostream>
#include<algorithm>
typedef long long ll;
const ll N = 1e5 + 5;
using namespace std;
ll t;
ll n, m;
ll sum;
struct num
{
	ll val;
	ll i;
	ll s;
	friend bool operator <(num& a, num&b)
	{
		if(a.s==b.s) 
			return a.i>b.i;
		return a.s>b.s;
	}
} arr[N];
int main()
{
		freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		sum = 0;
		for (ll i = 1; i <= n; i++)
		{
			
			cin >> arr[i].val;
			arr[i].i = i;
			sum += arr[i].val;
			arr[i].s=arr[i].val * (n - arr[i].i + 1);
			//sum-=arr[i]*(n-i+1)
			//之后会出现一个0
			//sum最小
		}
		//按单次操作价值大小排序
		sort(arr + 1, arr + n + 1);
		//按i排序
		//		sort(arr + 1, arr + m + 1, cmp);
		//		cout << arr[1].val;
		for (ll i = 1; i <= m; i++)
		{
			if (arr[i].val <= 0) break;
			sum-=arr[i].s;
			//			sum -= arr[i].val * (n - arr[i].i + 1);
			
		}
		cout << sum << "\n";
	}
	return 0;
}
