#include<iostream>
typedef long long ll;
using namespace std;
ll k, p;
bool cmp(ll mid)
{
	if(mid>=k) 
		return 1;
	int t=mid;
	while(1){
		if(t>=k||mid/p==0) break;
		t+=mid/p;
		mid=mid%p+mid/p;
	}
	if(t>=k ) return 1;
	return 0;
}
int main( )
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> p >> k;
		if (k == 1||k==0)
			cout << k << "\n";
		else
		{
			if(p>=k)
			{
				cout<<k<<"\n";
				continue;
			}
			else if(p==1)
			{
				cout<<p<<"\n";
			}
			else 
			{
				ll l = 0, r = k+1, mid;
				while (l < r)
				{
					mid = (l + r) >> 1;
					if (cmp(mid))
						r = mid;
					else
						l = mid + 1;
				}
				cout << l << "\n";
			}
		}
	}
	return 0;
}
