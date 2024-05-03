#include <iostream>
using namespace std;
int arr[102];
int temp[102];
int main() {
//	freopen("C://Temp//in.txt","r",stdin);
	int n,k;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	cin>>k;
	//1黑色,2黄色,0弃权
	bool f=0;//1表示没有大奖
	bool s=1;//1表示全都弃权
	for(int i=0; i<k; i++) {
		f=0;
		s=1;
		for(int j=0; j<n; j++) {
			cin>>temp[j];
			if(temp[j]) s=0;
			if(temp[j]!=0&&(temp[j]!=arr[j]))
				f=1;
		}
		if(f||s)
			cout<<"Ai Ya";
		else
			cout<<"Da Jiang!!!";
		if(i<k-1)
			cout<<"\n";
	}
	return 0;
}
