#include <iostream>
#include<cmath>
typedef long long ll;
const ll N = 1e5 + 1;
using namespace std;
ll h[N];
ll a[N];
ll n, m, k, b;
ll slove(ll i, ll M)
{
	if(M==1) 
		return h[i];
	if (a[i] >= k)
		return b;
	//��1+t1��Ϊb
	ll t1 = (k - h[i] ) / a[i];
	//��t2+1�����,1Ϊb
	ll t2 = (k - b) / a[i];
 

	if (M <= t1 + 1) 
	{
		ll T = h[i] + a[i] * (M - 1);
		if(T>k) return b;
		return T;
	}
	//��t1+1���п��ܸպ�Ϊk


	//�������,��һ��ΪbʱMΪ0
	M -= t1+2;
	M %= t2+1;
	//cout << b + a[i]*m << ' ';
	return b + a[i] * M;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k >> b;
		for (int i = 1; i <= n; i++)
		{
			cin >> h[i];
			if(h[i]>k) h[i]=b;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
//		slove(3);
		for (ll i = 1; i <= 30; i++)
		{
			cout << slove(2, i) << " ";
//			cout << slove(i,m) << " ";
		}
		cout << "\n";
	}
	return 0;
}
