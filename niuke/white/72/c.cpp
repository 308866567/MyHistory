#include <iostream>
using namespace std;
typedef long long ll;
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	ll n;
	cin>>n;
	ll a[n+1];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	ll t;
	ll z=0,f=0;
	for(int i=0; i<n; i++) {
		cin>>t;
		a[i]-=t;
		if(a[i]>0) z+=a[i]
		else f+=a[i];
	}
	if(z==f) cout<<z;
	else cout<<-1;
	return 0;
}
