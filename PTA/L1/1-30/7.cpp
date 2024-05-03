#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}
struct num
{
	long long a; // 分子
	long long b; // 分母
	num() {}
	num(long long x, long long y)
	{
		a = x;
		b = y;
	}
	struct num operator+(const num t) const
	{
		if (a == 0)
			return t;
		if (b == t.b) // 分母相同
			return num(a + t.a, b);
		else // 通分
		{
			long long zi = a * t.b + b * t.a;
			long long mu = b * t.b;
			long long g;
			if (zi > mu)
			{
				g = gcd(zi, mu);
			}
			else
			{
				g = gcd(zi, mu);
			}
			zi /= g;
			mu /= g;
			return num(zi, mu);
		}
	}
};
num arr[101];
int main()
{

	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	long long a, b;
	long long n;
	num ans(0, 0);
	scanf("%lld", &n);
	for (long long i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &a, &b);
		arr[i].a = a;
		arr[i].b = b;
		ans = ans + arr[i];
		// cout << ans.a << ' ' << ans.b << '\n';
	}
	if (ans.a == 0)
	{
		cout << 0;
		return 0;
	}
	long long s = ans.a / ans.b; // 整数
	ans.a %= ans.b;              // 分子
	if (s)
		cout << s;
	if (ans.a)
	{
		if (s)
			cout << ' ';
		cout << ans.a << '/' << ans.b;
	}
	return 0;
}
