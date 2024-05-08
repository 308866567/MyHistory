#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>
ll x,y;
int main() 
{
	cin>>x>>y;
	if(x<0) x=-x;
	if(y<0) y=-y;
	ll ans=11;
	ll d=x*x+y*y;
	for(int i=1;i<=10;i++){
	if(d<=i*i){
		ans-=i;
		break;
	}
	}
	cout<<ans;
}
