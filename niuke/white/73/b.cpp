#include <iostream>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	ll t=0;
//	cout<<gcd(1,2);
	cin>>t;
	ll n;
	while(t--)
	{
		cin>>n;
		cout<<n<<' '<<2*n;
	}
	return 0;
}
