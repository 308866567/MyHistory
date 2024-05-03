#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 2e3 + 100;
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

unordered_map<ll, ll> g;
ll n, x;
ll a[N]={0}, b[N]={0};
ll dp[N][N]={0};
void out() {
	for (int i = 1; i <= n + 2; i++) {
		for (int j = 1; j <= x; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
//	freopen("E:\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	
	//初始化
	for (int i = 1; i <= n; i++) {
		dp[i][a[i]] = b[i];
	}
	ll t;
	ll ans = -1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			if(i>0)
				dp[i][j]=max(dp[i-1][j],dp[i][j]);
			//半价买i+2
			t = j + a[i + 2] / 2 + a[i + 1];
			if (t <= x)
				dp[i + 2][t] = max(dp[i][j] + b[i + 2] + b[i + 1], dp[i + 2][t]);
			//原价买i+1
			t = j + a[i + 1];
			if (t <= x)
				dp[i + 1][t] = max(dp[i][j] + b[i + 1], dp[i + 1][t]);
			
			ans = max(dp[i][j], ans);
			
		}
	}
	//out();
	cout << ans;
	return 0;
}
