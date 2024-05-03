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
	for (auto it : u)//it.first为质因子的值 
	{
		ll sum=0;
		ll now=1;
		for(ll i=it.second;i>0;i--){
			sum=(sum+now)%N;
			now=now*it.first%N;
		}
		ans = ans *sum%N;
	}
	cout << ans;
	return 0;
}
