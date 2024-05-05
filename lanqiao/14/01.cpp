#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
//235
#define rep(i, start, end) for (ll i = start; i <= end; i++)
ll arr[200];
ll d[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unordered_map<ll,ll> g;
bool mouth(ll a, ll b)
{
	ll t=a*10+b;
	if(t>0&&t<13) return true;
	return false;
}
bool day(ll m, ll a, ll b)
{
	ll t = a * 10 + b;
	if (t > d[m] || t <= 0)
	{
		return false;
	}
	return true;
}
void slove()
{
	ll n = 100;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	ll ans = 0;
	rep(i1, 1, n)
	{
		if (arr[i1] != 2)
			continue;
		rep(i2, i1+1, n)
		{
			if (arr[i2] != 0)
				continue;
			rep(i3, i2+1, n)
			{
				if (arr[i3] != 2)
					continue;
				rep(i4, i3+1, n)
				{
					if (arr[i4] != 3)
						continue;
					rep(i5, i4+1, n)
					{
						if (arr[i5] >1)
							continue;
						rep(i6, i5+1, n)
						{
							if (!mouth(arr[i5], arr[i6]))
								continue;
							rep(i7, i6+1, n)
							{
								rep(i8, i7+1, n)
								{
									if (day(arr[i5] * 10 + arr[i6], arr[i7], arr[i8]))
									{
										// cout << arr[i1]<<' ' << arr [i2]<<' ' << arr [i3]<<' ' << arr[i4]<<' ' << arr[i5]<<' ' << arr[i6] <<' '<< arr[i7] <<' '<< arr[i8] <<' '<< "\n";
										ans++;
										// cout<<arr[i5]*1000+arr[i6]*100+arr[i7]*10+arr[i8]<<"\n";
										g[arr[i5]*1000+arr[i6]*100+arr[i7]*10+arr[i8]]++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<"\nans=";
	cout << g.size();
	return;
}
int main()
{
	freopen("/home/xiaobingdu/Downloads/in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		slove();
	}
	return 0;
}