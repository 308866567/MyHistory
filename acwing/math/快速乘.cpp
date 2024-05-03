#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
const ll mod = 10;

//o(1)
inline ll ksc(ll x, ll y, ll p)
{
	//a*b%mod=a%mod*b%mod
	//x%mod=x-floor(x/mod)*mod
	//ull一种自动溢出的数据类型（存满了就会自动变为0）
	ll z = x / p * y;
	ll res = (unsigned ll)x * y - (unsigned ll)z * p;
	return (res + p) % p;
}

//o(log2n)
inline ll ksc2(ll x, ll y, ll p) //计算x乘y的积
{
	ll res = 0; //加法初始化
	while (y)
	{
		if (y & 1)res = (res + x) % p; //模仿二进制
		x = (x << 1) % p;
		y >>= 1; //将x不断乘2达到二进制
	}
	return res;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	return 0;
}
