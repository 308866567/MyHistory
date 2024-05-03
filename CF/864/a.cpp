#include <iostream>
using namespace std;
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t;
	cin>>t;
	int n,m;
	int sx,sy,ex,ey;
	int s1,s2;
	int ans=0;
	while(t--) {
		s1=4;
		s2=4;
		cin>>n>>m;
		cin>>sx>>sy>>ex>>ey;
		if(sx==1||sx==n) s1--;
		if(ex==1||ex==n) s2--;
		if(sy==1||sy==m) s1--;
		if(ey==1||ey==m) s2--;
		ans=min(s1,s2);
		cout<<ans<<"\n";
	}
	return 0;
}
