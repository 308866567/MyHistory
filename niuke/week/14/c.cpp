#include <iostream>
using namespace std;
typedef  long ll;
const ll N = 2e5 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

#include<bitset>
ll used[30];
ll n, l, r;
char arr[N];
ll size = 0;
ll cal()
{
	ll s = 0;
	for (int i = 0; i <= n; i++)
	{
		if (used[i]) s++;
	}
	size = s;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> l >> r;
	cin >> arr + 1;
	ll ans = 0;
	ll a = 1, b = 1;
	ll t = arr[b] - 'a';
	used[t]++;
	size = 1;
	while ( b<=r)
	{
		while (b<=r&&size < l)
		{
			b++;
			t = arr[b] - 'a';
			used[t]++;
			cal();
		}
		while (b<=r&&size >= l && size <= r)
		{
			ans++;
			b++;
			t = arr[b] - 'a';
			used[t]++;
			cal();
		}
		while (a<=r&&size > r)
		{
			t = arr[a] - 'a';
			used[t]--;
			a++;
			cal();
		}
	}
	cout << ans;
	return 0;
}

