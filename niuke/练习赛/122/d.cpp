#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4;
ll dp[N][N];
//线段合并,和区间不相交的可以合并
ll n, m;
unordered_map<ll, unordered_map<ll, ll>> g;
ll sum, ans;
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	cin >> n >> m;
	for (ll i = 1,x,y,w; i <= m; i++) {
		cin >> x >> y >> w;
		if (x > y) {
			swap(x, y);
		}
		g[x][y] = w;
		g[y][x + n] = w;
		sum += w;
	}


	for (int i = 1; i <= 2 * n; i++) { //终点
		for (int j = i - 1; j > 0; j--) { //起点
			dp[j][i] = dp[j+1][i]; //继承子区间
			for (auto k : g[j]) {
				ll r =	k.first; //j->r
				ll w = k.second;//权值
				//j r i
				if (r > i) {
					continue;
				}
				//加上k线段所在区间里的dp
				if (j + 1 < r - 1) {
					w += dp[j + 1][r - 1];
				}
				//加上线段和终点i中间区间的值
				if (r + 1 < i) {
					w += dp[r + 1][i];
				}
				dp[j][i]=max(dp[j][i],w);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][i + n - 1 ]);
	}
	cout << sum - ans << "\n";
//	for (int i = 1; i <= 2*n; i++) {
//		for (int j = 1; j <=2*n; j++) {
//			cout << dp[i][j] << ' ';
//		}
//		cout << "\n";
//	}
	return 0;
}
