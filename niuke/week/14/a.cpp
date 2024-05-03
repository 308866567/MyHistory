#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

char a[N];
//
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll maxx = 0;
	a[0] = '!';
	ll ans = 0;
	char x;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x == a[maxx])
		{
			maxx--;
			ans+=2;
			continue;
		}
		a[++maxx] = x;
	}
	ll l = 1, r = maxx;
	while (l < r && a[l] == a[r])
	{
		l++, r--;
		ans += 2;
	}
	cout << ans;
	return 0;
}

