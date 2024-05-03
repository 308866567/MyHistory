#include <iostream>
#include <string>
using namespace std;
int s(long long x) {
	int ans=0;
	while(x!=0) {
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main() {
//	freopen("C://Temp//in.txt","r",stdin);
	int n;
	cin>>n;
//	cout<<s(n);
	long long  a,b;
	int sa,sb;
	bool f1,f2;
	for(int i=0; i<n; i++) {
		cin>>a>>b;
		f1=0;
		f2=0;
		sa=s(a);
		sb=s(b);
		if(a%sb==0) f1=1;
		if(b%sa==0) f2=1;
//		cout<<f1<<' '<<f2;
		if(f1&&!f2) {
			cout<<"A";
		} else if(!f1&&f2) {
			cout<<"B";
		} else {
			if(a>b)cout<<"A";
			else cout<<"B";
		}
		if(i<n-1)cout<<"\n";
	}
	return 0;
}
