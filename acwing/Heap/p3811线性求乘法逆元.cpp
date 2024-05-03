#include <iostream>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	else
	{
		ll ans = exgcd(b, a % b, x, y);
		ll t = x;
		x = y;
		y = t - a / b * y;
		return ans;
	}
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	ll n, p;
	ll x,y;
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		//ix+py=1,Çóx
		exgcd(i,p,x,y);
		if(x<0) 
			x+=p;
		cout<<x<<"\n";
	}
	return 0;
}
