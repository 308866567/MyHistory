#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

ll t, x, y;
ll a[10], b[10];
void slove1()//x的因子6个数
{
	while (x % 6 == 0)
	{
		x /= 6;
		a[6]++;
	}
	while (x % 5 == 0)
	{
		x /= 5;
		a[5]++;
	}
}

int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		ll ans = 0;
		cin >> x >> y;
		if (y != x) ans = -1;
		cout << ans << "\n";
	}
	return 0;
}

