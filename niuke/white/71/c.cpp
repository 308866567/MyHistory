#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
#define M 1e18
int main() {
	ll p,q;
	cin>>p>>q;
	unsigned long long t;
	ll i=3;
	while(t<=M) {
		t=pow(p,q);
		if(t<p)
			break;
		p=q;
		q=t;
		i++;
	}
	cout<<i-1<<"\n";
	return 0;
}
