#include <iostream>
using namespace std;
int main() {
//	freopen("C://Temp//in.txt","r",stdin);
	int n;
	cin>>n;
	int a,b,c;
	while(n--) {
		cin>>a>>b>>c;
		if(c==a*b) {
			cout<<"Lv Yan";
		} else if(c==a+b) {
			cout<<"Tu Dou";
		} else {
			cout<<"zhe du shi sha ya!";
		}
		if(n>0)cout<<"\n";
	}
	return 0;
}
