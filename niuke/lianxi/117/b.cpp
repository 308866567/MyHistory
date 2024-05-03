#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>
ll n;
ll a[N];
ll l,r,k;

ll cal(ll x){
	return  (x + x%2) / 2;
	if(x&1) return x/2+1;
	else return x/2;
}

int main() {
//	freopen("E:\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		cin>>l>>r>>k;
		ll sum=cal(r)-cal(l-1);
		//看末尾
		if(sum&1)
			cout<<1<<"\n";
		else 
			cout<<0<<"\n";
	}
	return 0;
}
