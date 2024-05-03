#include <iostream>
#include<cstring>
typedef long long ll;
const ll N = 2e5 + 3;
using namespace std;
ll a[N] = {0};//原数组
ll t[N] = {0}; //出现次数前缀和
ll n;
ll lmax[N] = {0}, lmin[N] = {0};
ll rmax[N] = {0}, rmin[N] = {0};
inline ll lowbit(ll x)
{
	return x & (-x);
}
//查询1-x
inline ll query(ll x)
{
	ll sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
	{
		sum += t[i];
	}
	return sum;
}
//区间查询
inline ll query(ll l, ll r)
{
	return query(r) - query(l - 1);
}
//单点修改
inline void update(ll x, ll k)
{
	for (int i = x; i <= n; i+=lowbit(i))
	{
		t[i] += k;
	}
}
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	//下三角=左大*右大
	//处理左边
	for (int i = 1; i <= n; i++)
	{
		update(a[i],1);
		// t[a[i]]++;
		//查询
		lmin[i] = query(a[i] -1); //1,t[a[i]]-1
		lmax[i] = query(a[i] +1,n); //t[a[i]]+1,n
	}
	ll ans1 = 0, ans2 = 0;
	//上三角=左小*右小
	memset(t,0,sizeof(t));
	for (int i = n; i > 0; i--)
	{
		update(a[i],1);
		//查询
		rmin[i] = query(a[i] -1); //1,t[i]-1
		rmax[i] = query(a[i] +1, n); //t[i]+1,n
		ans1 += lmax[i] * rmax[i];
		ans2 += lmin[i] * rmin[i];
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
