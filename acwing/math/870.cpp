#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e9 + 7;
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll n, a;
	ll ans = 1;
	unordered_map <ll, ll> u;
	cin >> n;
	while (n--)
	{
		cin >> a;
		//a分解质因数,存
		for (ll i = 2; i <= a / i; i++)
		{
			while (a % i == 0)
			{
				a /= i;
				u[i]++;
			}
		}
		if (a > 1)
			u[a]++;
	}
	//设a=b*c
	//构造b由a的质因子组合而成,c则由b组合剩下的质因子组成,所以不用管c
	//对于每个质因子,有0,1,2...种选法
	//每个因子的选法相乘即为不相等的b的种数
	//不*2是因为约数是一一对应的,组成b会出现所有的情况
	for (auto it : u)
	{
		ans = ans * (it.second + 1) % N;
	}
	cout << ans;
	return 0;
}
