#include <iostream>
using namespace std;
typedef long long ll;
int main() {
//     freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	ll n=10;
	cin>>n;
	ll now;
	ll minn=0x3f3f3f3f3f;
	for(int i=0; i<n; i++) {
		cin>>now;
		if(now<=minn)
        {minn=now;cout<<"NO";
        return 0;}
	}
// 	cin>>now;
// 	if(now<=minn)
//         cout<<"NO";
// 	else
		cout<<"YES";
	return 0;
}s
