#include <iostream>
using namespace std;
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	string a;
	int t, len;
	int ans = 0;
	int f = 0;
	cin >> t;
	while (t--)
	{
		cin >> a;
		len = a.size();
		ans = 0;
		f=0;
		for (int i = 0; i < len; i++)
		{
			if (a[i] == '_')
				f++;
			else 
				f = 0;
			if(f==2){
				f=1;ans++;
			}
		}
		if(a[0]=='_')ans++;
		if(a[len-1]=='_')ans++;
		if(a[len-1]=='^'&&len==1)ans=1;
		cout<<ans<<"\n";
	}
	return 0;
}
