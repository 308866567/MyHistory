#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

ll n, m;
ll f[N], V[N], W[N], C[N], q[N];
ll calc(int i, int u, int k)
{
	return f[u + k * V[i]] - k * W[i];
}
void slove1()
{
	memset(f, 0xcf, sizeof (f));
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> W[i] >> V[i] >> C[i];
		for (int u = 0; u < V[i]; u++)
		{
			int l = 1, r = 0;
			int maxp = (m - u) / V[i];
			for (int k = maxp -1; k >= max(maxp - C[i], (ll)0); k--)
			{
				while (l <= r && calc(i, u, q[r]) <= calc(i, u, k))r--;
				q[++r] = k;
			}
			for (int p = maxp; p >= 0; p--)
			{
				while (l <= r && q[l] > p - 1)l++;
				if (l <= r)
					f[u + p * V[i]] = max(f[u + p * V[i]],
					                      calc(i, u, q[l])+p*W[i]);
				if (p - C[i] - 1 >= 0)
				{
					while (l <= r &&
					       calc(i, u, q[r]) <= calc(i, u, p - C[i] - 1)) r--;
					q[++r] = p - C[i] - 1;
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		ans=max(ans,f[i]); 
	}
	cout<<ans;
}

int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	slove1();
	return 0;
}

