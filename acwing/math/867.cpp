#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 111;
int main()
{
	int n;
	ll a;
	ll s;
	cin >> n;
	while (n--)
	{
		cin >> a;
		for (ll i = 2; i <= a / i; i++)
		{
			s = 0;
			while (a % i == 0)
			{
				a /= i;
				s++;
			}
			if (s > 0)
				cout << i << ' ' << s << "\n";
		}

		if (a > 1) cout << a << ' ' << 1 << "\n"; //a为质数的时候
		cout << "\n";
	}
	return 0;
}
