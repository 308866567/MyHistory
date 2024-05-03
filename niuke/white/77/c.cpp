#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
ll n, m, k;
ll ans = 0;
ll idx = 1;
struct node
{
	ll u, v;
	bool f;
	void set(ll a, ll b)
	{
		u = a;
		v = b;
		f = 0;
	}
	const bool operator< (const node &t)
	{
		if (u == t.u) return v < t.v;
		return u < t.u;
	}
} arr[N];


ll s[N];
ll sum = 0;
//
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	ll a, b;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if (a != b)
		{
			arr[idx++].set(a, b);
		}
	}
	sort(arr + 1, arr + idx );
	m = idx - 1;
	idx--;
	while (idx > 0)
	{
		for (int j = 1; j <= n; j++)
		{
			int now = j;
			if (s[now] > 0)
			{
				sum -= s[now];
				idx -= s[now];
				s[now] = 0;
			}
			for (int i = 1; i <= m; i++)
			{
				if (!arr[i].f && sum < k) //放入购物车
				{
					arr[i].f = 1;
					sum++;
					s[arr[i].v]++;
				}
				if(sum==k||arr[i].u>j) break;
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}
