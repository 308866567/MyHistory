#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll arr[N];
//质数 2 3 5
//特判3
ll prime[N];//0表示为质数
void init()
{
	prime[0] = prime[1] = 1;
	rep(i, 2, N - 1)
	{
		if (!prime[i])
		{
			for (ll j = i + i; j < N; j += i)
				prime[j] = 1;
		}
	}
}
void solve()
{
	ll n;
	cin >> n;
	ll sum = 0;//质数个数
	ll sum3 = 0;
	rep(i, 1, n)
	{
		cin >> arr[i];
		if (!prime[arr[i]]) sum++;
		if (arr[i] == 3) sum3 ++;
	}
	ll ans = 2;
//	cout<<sum<<"---";
	//奇数
	if ((sum + sum3) & 1) ans = 0;
	else
	{
		if(sum== sum3 ) ans=-1;
		else 
		ans = 1;
	}
	//没有质数
	if ((sum + sum3) == 0) ans = -1;
	cout << ans << "\n";
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
	cin >> t;
	init();
	while (t--)
	{
		solve();
	}
	return 0;
}
