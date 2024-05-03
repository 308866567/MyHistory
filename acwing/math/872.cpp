#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e9 + 7;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll n, a,b;
	cin >> n;
	while (n--)
	{
		cin>>a>>b;
		cout<<gcd(a,b);
	}
	return 0;
}
