#include <iostream>
#define mod 998244353
using namespace std;
typedef long long ll;
int a[400009];//lmin~rmax数字出现次数
int l[400009], r[400009];//m个区间的左右边界
int n,m;
ll sum;
int main()
{
	// 	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	cin >> n >> m;
	ll lmin = 99999999, rmax = -1;
	for (int i = 0; i < m; i++)
	{
		cin >> l[i] >> r[i];
		if (l[i] < lmin) lmin = l[i];
		if (r[i] > rmax) rmax = r[i];
		a[l[i]]++;
		a[r[i] + 1]--;
	}
	for (int i = 0; i <= 400009; i++) //一次前缀和
	{
		a[i + 1] = (a[i]+	a[i + 1])%mod;
	}
	for (int i = 0; i <= 400009; i++) //二次前缀和
	{
		a[i + 1] = (a[i]+	a[i + 1])%mod;
		//		cout << a[i] << " ";
	}
	//	cout << "sum:" << sum << "\n";
	for (int i = 0; i < m; i++) //穷举m个区间
	{
		int rr = n - l[i];
		int	ll = max(1, n - r[i]);
		if (ll > rr) continue;
		sum=(sum+mod+a[rr]-a[ll-1])%mod;//所有情况和
		//		cout<<sum<<" ";
		sum=(sum+mod- max(0, min(rr, r[i]) - max(ll, l[i]) + 1))%mod;
		//		cout<<sum<<"\n";
	}
	cout << sum;
	return 0;
}
