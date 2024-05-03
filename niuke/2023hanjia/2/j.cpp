#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t;
	cin >> t;
	ll sum = 0;
	ll n,x;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if(x<0) x=-x;
			sum+=x;
		}
		sum=sum*n*2;
		cout<<sum<<"\n";
	}
	return 0;
}
