#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#include<cmath>


ll a;
ll b;
ll ans = 0;
//
int main()
{
//	freopen("C:\/\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		cin >> a >> b;
		ans = 0;
		if (a == b)
		{
			cout << "0\n";
		}
		else if (b == a + 1 || b == 2 * a || b == a * a)
		{
			cout << "1\n";
		}
		else
		{
			while (b > a)
			{
				ans++;
				double p = sqrt(b);
				if (p * p == b)
				{
					b = p;
					continue;
				}
				else if (b % 2 == 0)
				{
					b /= 2;
				}
				else
				{
					b--;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
