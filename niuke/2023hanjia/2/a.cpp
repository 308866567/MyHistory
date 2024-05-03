#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	ll n;
	ll l1, r1, l2, r2, minn, maxx;
	cin >> t;
	while (t--)
	{
		ll sum = 0;
		cin >> n;
		cin >> l1 >> r1;
		cin >> l2 >> r2;
		//穷举a
		minn = n - r1;//a=r1时,b取值
		if (minn < l2) minn = l2;
		else if (minn > r2)
		{
			cout << 0 << '\n';
			continue;
		}
		maxx = n - l1;//a=l1时,b取值
		if (maxx > r2) maxx = r2;
		else if (maxx < l2)
		{
			cout << 0 << '\n';
			continue;
		}
		sum=maxx-minn+1;
			cout << sum << '\n';
	}
	return 0;
}
