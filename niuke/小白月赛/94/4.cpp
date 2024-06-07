#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll arr[N];
vector<ll> ans;
bool v[N];
ll gcd(ll a, ll b)
{
	return a > 0 ? b % a : b;
}
void solve()
{
	cin >> n;
	arr[0] = n;
	rep(i, 1, n)
	{
		cin >> arr[i];
		// if (arr[i] > n || arr[i] > arr[i - 1])
		// {
		// 	cout << -1 << "\n";
		// 	return;
		// }
	}
	// ans.emplace_back(arr[1]);
	// v[arr[1]] = 1;
	ll s=0;
	rep(i, 1, n)
	{
		if(i!=1&&arr[i]>arr[i-1]){
			cout << -1 << "\n";
			return;
		}
		ll t = arr[i];
		while (t <= n)
		{
			if (!v[t])
			{
				ans.emplace_back(t);
				v[t] = 1;
				break;
			}
			t += arr[i];
		}
		s=i;
		if (arr[i] == 1)
			break;
	}
	
	if (ans.size() < s)
	{
		cout << -1 << "\n";
		return;
	}
	rep(i, 1, n)
	{
		if (!v[i])
			ans.emplace_back(i);
	}
	rep(i, 1, ans.size())
	{
		if (i == 1)
			cout << ans[0];
		else
			cout << " " << ans[i - 1];
	}
	cout << "\n";
}

int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
	freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
