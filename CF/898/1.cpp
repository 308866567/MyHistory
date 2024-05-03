#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

unordered_map<ll, unordered_map<ll, ll>> g;
//
void slove()
{
	string t;
	cin >> t;
	ll sum = 0;
	if (t[0] != 'a') sum++;
	if (t[1] != 'b') sum++;
	if (t[2] != 'c') sum++;
	if (sum <= 2)cout << "yes\n";
	else cout << "no\n";
}
int main()
{
//freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		slove()
		;
	}

	return 0;
}

