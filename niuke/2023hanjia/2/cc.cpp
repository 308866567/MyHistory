#include <iostream>
#define mod 998244353
using namespace std;
typedef long long ll;
ll a[400009];//���ֳ��ִ���
ll tl, tr;
ll n, m;
ll sum;
ll res (ll l, ll r)
{
	ll sum = 0;
	return sum;
//	ll res = min(tr, n - tl) - max(tl, n - tr) + 1;
//	res = max(res, 0ll);
}
ll Add(ll L, ll R)//��ѡ����ѡn,����Ϊ2,x��n-x,n-x��x,0��n,n��0
{
	if (L > n) return 0;
	//  l,n,r
	ll y = n - L;//�ұ߽�
	ll x = n - R;//��߽�
	if (y > R)
		y = R;
	if (x < L)
		x = L;
	//  return y - x + 1;
	return y - x + 1 > 0 ? y - x + 1 : 0;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		cin >> tl >> tr;
//		sum -= res(tl, tr);
		sum -= Add(tl, tr);
		sum %= mod;
		a[tl]++;
		a[tr + 1]--;
	}
	for (ll i = 0; i <= 400000; i++)//һ��ǰ׺��
	{
		a[i + 1] = (a[i] +	a[i + 1]) % mod;
	}
	for (ll i = 0; i <= n; i++)//i��j�������
	{
//		cout << i << ":" << a[i] << "\n";
		ll j = n - i;
		sum = sum + a[i] * a[j];
		sum %= mod;
	}
	sum %= mod;
	cout << sum;
	return 0;
}
