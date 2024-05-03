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
inline void slove(ll a, ll b, ll c)
{
	ll x, y;
	ll d = exgcd(a, b, x, y); //最大公约数
	//无整数解
	if (c % d != 0)
	{
		cout << -1 << "\n";
		return ;
	}
	else
	{
		//(x,y)a/g*x*c+b/g*y*c=c的特解
		a /= d;
		b /= d;
		c /= d;
		exgcd(a, b, x, y);
		x *= c;
		y *= c;
		ll minx = x > 0 && x % b != 0 ? x % b : x % b + b; //xmin
		ll maxy = (c - a * minx) / b;
		ll miny = y > 0 && y % a != 0 ? y % a : y % a + a; //ymin
		ll maxx = (c - b * miny) / a;
		if (maxx > 0)
		{
			//有正整数解
			cout << (maxx - minx) / b + 1 << ' ';
			cout << minx << ' ' << miny << " ";
			cout << maxx << ' ' << maxy << "\n";
		}
		else
		{
			//有整数解,无正整数解
			cout << minx << ' ' << miny << "\n";
		}
		return ;
	}
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, c;
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		slove(a, b, c);
	}
	return 0;
}
