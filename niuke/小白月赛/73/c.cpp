#include <iostream>
#include<algorithm>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
ll arr[1001];
void slove(){
	
}
	
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	ll t;
	cin>>t;
	ll n;
	bool f;
	while(t--)
	{
		f=true;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		for(int i=1;i<n;i++){
			if(arr[i]==arr[i-1]) {
				f=false;
			}
		}
		if(f){
			for(int i=0;i<n;i++){
				cout<<arr[i]<<' ';
			}
			cout<<"\n";
		}else{
			cout<<"-1"<<"\n";
		}
	}
	return 0;
}
