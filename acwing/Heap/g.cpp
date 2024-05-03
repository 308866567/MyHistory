#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 1;
priority_queue<ll, vector<ll>, greater<ll>> q;
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll n;
	ll sum = 0;
	ll a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			q.push(b - sum);
		}
		else if (a == 2)
		{
			cin >> b;
			sum += b;
		}
		else
		{
			cout << q.top() + sum << "\n";
			q.pop();
		}
	}
	return 0;
}
