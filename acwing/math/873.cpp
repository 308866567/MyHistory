#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 10;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//欧拉公式
//res表示1~n中与n互质的个数
//res=n*(求和(pi-1)/p1)
//首先， 欧拉函数是一个积性函数，当m,n互质时，φ(mn)=φ(m)?φ(n)
ll phi(ll x)
{
	ll res = x;
	for (int i = 2; i <= x / i; i++)//约数成对出现,i*i<=x
	{
		if (x % i == 0)//x分解质因数
		{
			res = res / i * (i - 1);//欧拉公式
			while (x % i == 0)//除取这个质因子
				x /= i;
		}
	}
	if (x > 1) res = res / x * (x - 1);
	return res;
}
int main()
{
	//	fre;
	fast;
	int n;
	cin >> n;
	while (n -- )
	{
		int x;
		cin >> x;
		cout << phi(x) << endl;
	}
	return 0;

	return 0;
}
