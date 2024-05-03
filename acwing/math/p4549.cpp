#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
ll arr[30];
//
ll gcd(ll a,ll b){
	if(a==0 )return b;
	if(b==0) return a;
	if(!(a&1)&&!(b&1))
		return gcd(a>>1,b>>1)<<1;
	else if(!(a&1))
		return gcd(a>>1,b);
	else if(!(b&1))
		return gcd(a,b>>1);
	return gcd(abs(a-b),min(a,b));
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		ans=gcd(ans,abs(arr[i]));
	}
	cout<<ans;
	return 0;
}
