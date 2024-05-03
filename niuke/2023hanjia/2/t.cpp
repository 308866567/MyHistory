#include <iostream>
#define mod 998244353
using namespace std;
typedef long long ll;
ll a[409];//数字出现次数
ll n, m;
ll sum;
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	ll l[202], r[202];
	ll lmin = 999999, rmax = -1;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> l[i] >> r[i];
//		if (l[i] < lmin) lmin = l[i];
//		if (r[i] > rmax) rmax = r[i];
//		a[l[i]]++;
//		a[r[i]]--;
//	}
//	if (n < rmax) rmax = n;
//	if (n < lmin)
//	{
//		cout << 0;
//		return 0;
//	}
//	ll x = 0, y = 0;
//	for (int i = lmin; i < rmax; i++)
//	{
//		sum += a[i];
//		a[i + 1] += a[i];
//	}
//	for (int i = 0; i < m; i++) //m个区间自减
//	{
//		sum -= Add(l[i], r[i]);
//	}
//	cout << sum;
	return 0;
}
