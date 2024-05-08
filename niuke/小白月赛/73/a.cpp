#include <iostream>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	ll n;
	cin>>n;
	ll x=n%3;
	n+=3-x;
	cout<<n;
	return 0;
}
