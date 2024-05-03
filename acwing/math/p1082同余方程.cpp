#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
inline ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)//gcd(a,0)=a
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		ll d = exgcd(b, a % b, x, y);
		ll t = x;
		x = y;
		y = t - a / b * y;
		return d;
	}
}
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, c=1;
	cin>>a>>b;
	//ax%b=1
	//ax+by=1
	ll x,y;
	ll d=exgcd(a,b,x,y);
	if(x<0) 
		x+=b;
	cout<<x;
	return 0;
}
