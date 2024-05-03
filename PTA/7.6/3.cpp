#include <iostream>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
int t, n;
int main()
{
	//freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >>n;
		ll ans =1;
		ans = n*(n-1)*(n-2)/6;
		ll ans1 = 0;
		for(int i =1 ;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				ans1+=max(0,n-i-j);
			}
		}
		cout << ans1<<" ";
		printf("%.3lf\n",1.0*ans1/ans);
	}
	return 0;
}
