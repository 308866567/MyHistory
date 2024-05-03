#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
#define M 1e18
ll gcd(ll  a,ll b) {
	return b==0?a:gcd(b,a%b);
}
/*
gcd(a+c, b+c) ≠ 1 等价于 gcd(a-c, b-c) ≠ 1
*/
int main() {
	ll a,b;
	cin>>a>>b;
	//穷举c,从a-b开始到min(a,b)
	ll aa=max(a,b),bb=min(a,b);
	ll d=aa-bb;
	//差为奇数时
	if(d%2) {
		for(int c=min(d,bb); c<max(bb,d); c++) {
			if(gcd(a-c,b-c)>1) {
				cout<<c;
				return 0;
			}
		}
		cout<<-1;
	}
	//差为偶数时
	else {
		cout<<d/2;
		return 0;
	}
	return 0;
}
