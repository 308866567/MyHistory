#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> dp;
ll f(ll n)//统计前1en有多个含4的数
{
	dp[n];
	if (dp[n])
		return dp[n];
	else
		dp[n] = f(n/10)*10+n/10-f(n/10);
	return dp[n];
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	dp[1]=0;
	dp[10]=1;
//	dp[100]=18;
	cout<<f(1e12)-f(1e11);
	//	cout << f(45);
	int t = 0;
//	cin >> t;
	while (t--)
	{
		
	}
	return 0;
}
