#include <iostream>
#include<cmath>
using namespace std;
//i*i数的因子为奇数
/*
1 1
2 4
3 9
4 16
5 25
*/
int f(int x) {
	int a=sqrt(x);
	int b=a+1;
	return a;
}
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t;
	int n;
	cin>>t;
	while(t--) {
		cin>>n;
		cout<<f(n);
	}
	return 0;
}
