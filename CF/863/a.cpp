#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define M 1e18
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	int t;
	cin>>t;
	int n,d;
	char x='0';
	string arr;
	int i;
	bool f=0;
	while(t--) {
		cin>>n>>d;
		x='0'+d;
		cin>>arr;
		f=0;
		i=0;
		if(arr[0]<x){
			cout<<x<<arr<<"\n";
			continue;
		}
		for(; i<n-1; i++) {
			if(arr[i]>=x&&arr[i+1]<x) {
				f=1;
				cout<<arr[i];
				cout<<x;
				i++;
				break;
			} 
			else
				cout<<arr[i];
		}
		for(; i<n; i++) {
			cout<<arr[i];
		}
		if(!f) cout<<x;
		cout<<"\n";
	}
	return 0;
}
