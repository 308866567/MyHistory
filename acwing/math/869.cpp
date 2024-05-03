#include <iostream>
using namespace std;
typedef long long ll;
const long long N = 1e4 + 1;
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll n,a;
	cin>>n;
	ll t[N],cnt=0;
	while(n--)
	{
		cin>>a;
		cnt=0;
		for(ll i=1;i<=a/i;i++){
			if(a%i==0) {
				cout<<i<<' ';
				if(i!=a/i)
				t[cnt++]=a/i;
			}
		}
		for(ll i=cnt-1;i>=0;i--)
			cout<<t[i]<<' ';
		cout<<"\n";
	}
	return 0;
}
