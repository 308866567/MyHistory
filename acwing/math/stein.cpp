#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

ll stein(ll a, ll b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if(a<0) a=-a;
	if(b<0) b=-b;
	if (!(a & 1) && !(b & 1)) //两偶数
		return stein(a >> 1, b >> 1) << 1;
	else if (!(a & 1)) //a偶数
		return stein(a >> 1, b);
	else if (!(b & 1))
		return stein(a, b >> 1);
	//两奇数就直接相减
	return stein(abs(a - b), min(a, b));
}
//
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		cout<<stein(a,b)<<"\n";
	}
	return 0;
}
