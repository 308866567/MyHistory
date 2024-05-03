#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
#define M 1e18
ll gcd(ll  a,ll b) {
	return b==0?a:gcd(b,a%b);
}
/*
gcd(a+c, b+c) �� 1 �ȼ��� gcd(a-c, b-c) �� 1
*/
int main() {
	ll a,b;
	cin>>a>>b;
	//���c,��a-b��ʼ��min(a,b)
	ll aa=max(a,b),bb=min(a,b);
	ll d=aa-bb;
	//��Ϊ����ʱ
	if(d%2) {
		for(int c=min(d,bb); c<max(bb,d); c++) {
			if(gcd(a-c,b-c)>1) {
				cout<<c;
				return 0;
			}
		}
		cout<<-1;
	}
	//��Ϊż��ʱ
	else {
		cout<<d/2;
		return 0;
	}
	return 0;
}
