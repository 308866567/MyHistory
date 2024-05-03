#include <iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 1;
unordered_map<ll, unordered_map<ll, ll>> g;
ll exgcd(ll a, ll b, ll &x, ll &y) //返回最大公约数
{
	//求ax+by=gcd(a,b)的一组解(x1,y1)
	if (!b)
	{
		//边界情况,当b=0时,
		//始终有解为(1,0)
		//1*a+0*b=a=gcd(a,0)
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, x, y);
	//通过回溯求原方程的解(x1,y1)
	//2表示底层
	ll t = x;
	x = y;//x1=y2
	y = t - (a / b) * y;//y1=x2-(a/b)*y2
	return d;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll a = 24, b = 18, x = 0, y = 0;
//	cin >> a >> b;
	ll d = exgcd(a, b, x, y);
	cout << d << "\n";
	cout << x << " " << y << "\n";

	//求解ax+by=k的解
	ll k;
	if (k % d == 0) //k能被gcd(a,b)整除则有解
	{
		x = x * k / d;
		y = (k - a * x) / b;
	}
	else
	{
		cout << "无解";
	}
	return 0;
}
