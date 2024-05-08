#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>
ll x, y;
ll h[N], a[N];
ll n;
bool st[N];
ll ans = -1;
ll used[N];//存储以i状态能击败的最多数

bool cmp(ll x, ll y) {
	return h[x] > h[y] && a[x] > a[y];
}
//sum为到x之前的击败数
//used统计子节点的深度
ll dfs(ll x, ll sum) {
	ans = max(ans, sum);
	ll maxd = -1;
	for (int i = 1; i <= n; i++) {
		if (cmp(x, i) && !st[i] ) {
			if (used[i] == -1) {
				st[i] = 1;
				maxd = max(	maxd, dfs(i, sum + 1));
				st[i] = 0;
				used[i] = max(used[i], maxd - sum);
			} else {
				ans = max(ans, sum + used[i]);
			}
		}
	}
	return sum ;
}
int main() {
//	freopen("E:\\in.txt", "r", stdin);
	memset(used,-1,sizeof used);
	cin >> n >> h[0] >> a[0];
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}
