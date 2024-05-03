#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
//https://codeforces.com/contest/510/problem/D
ll n;
unordered_map<ll,ll> dp;//数,代价
struct card {
	ll l;
	ll c;
	bool operator<(const card &A) const {
		return c<A.c;
	}
} arr[301];
ll gcd(ll a,ll b) {
	return b==0?a:gcd(b,a%b);
}
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>arr[i].l;
	}
	for(int i=0; i<n; i++) {
		cin>>arr[i].c;
	}
	//验证所有能组成的gcd中是否有1即可
	//gcd的传递性
	ll r=arr[0].l;
	ll ans=arr[0].c;
	ll tl,tc;
	for(int i=0; i<n; i++) {
		tl=arr[i].l;
		tc=arr[i].c;

		for(auto it:dp) {
			ll l=gcd(tl,it.first);
//			cout<<tl<<" "<<it.first<<' ' ;
//			cout<<l<<"\n";
			ll c=it.second;
			dp[l]=dp[l]?min(dp[l],c+tc):c+tc;
		}
		dp[tl]=dp[tl]?min(dp[tl],tc):tc;

//		if(r==1) {
//			cout<<ans;
//			return 0;
//		}
//		r=gcd(r,arr[i].l);
//		ans+=arr[i].c;
	}
	cout<<(dp[1]?dp[1]:-1);
	return 0;
}
