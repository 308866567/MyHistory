#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 12 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

unordered_map<ll, unordered_map<ll, ll>> g;
//
ll arr[N];
ll slove()
{
	ll n;
	cin >> n;
	memset(arr,0,sizeof arr);
	ll x;
	ll minn=0x3f3f3f3f;
	ll ans = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x != 0) ans *= x;
		arr[x]++;
		minn = min(x, minn);
	}
	if (minn == 0)
	{
		if (arr[0] == 1) return ans;
		else return 0;
	}
	else
	{
		ans /= minn;
		return (ans * (minn + 1));
	}
}
int main()
{
	//freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cout <<
		     slove() << "\n"
		     ;
	}

	return 0;
}

