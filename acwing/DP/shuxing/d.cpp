#include <iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 1;
unordered_map<ll,unordered_map<ll,ll>> g;
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	ll a,s;
	cin>>t;
	while(t--)
	{
		cin>>a>>s;
		if(s>=2*a&&((s-2*a)&a)==0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
