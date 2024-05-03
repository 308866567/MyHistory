#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> dp;
ll f(ll n)
{
	dp[n];
	if (dp[n])
		return dp[n];
	else
		dp[n] = f(n - 1) + f(n - 2);
	return dp[n];
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	dp[-1] = 1;
	dp[0] = 1;
	dp[1] = 1;
	//	cout << f(45);
	int t = 0;
	int n, x, y;
	cin >> t;
	while (t--)
	{
		cin >> n >>y >> x;//y––x¡–
//		cout<<f(4)<<' '<<f(5)<<"\n";
		if (x > f(n - 1) && x < f(n + 1) - f(n - 1) + 1)
		{
			cout << "NO";
		}
		else if (n==1&&y >1&&y<n)
		{
			cout << "NO";
		}
		else if (n>1&&y > f(n - 2) && y < f(n ) - f(n - 2) + 1)
		{
			cout << "NO";
		}
		else
		{
			cout << "YES";
		}
		cout << "\n";
	}
	return 0;
}
