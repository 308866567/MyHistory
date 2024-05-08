#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll a[2],b[2];
	cin>>a[0]>>a[1]>>b[0]>>b[1];
	ll t=a[0];
	if(a[0]<a[1]) {
		a[0]=a[1];
		a[1]=t;
	}
	t=b[0];
	if(b[0]<b[1]) {
		b[0]=b[1];
		b[1]=t;
	}
	if(b[0]>=a[0]&&b[1]>=a[1]) {
		cout<<"YES";
		return 0;
	}
	else cout<<"NO";
	return 0;
}
