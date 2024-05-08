#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

const ll mod = 998244353;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>


ll dp[N][3];
//0表示any，除1,2状态外的合法状态
//1表示末尾为t的
//2表示末尾为tx的
ll qmi(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if ((b & 1) != 0) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

//递推计算不含txt串的种类数
void slove() {
	ll n;
	cin >> n;
	ll ans = qmi(26, n); //总种类数
/*


 */
	dp[0][0]=25;
	dp[0][1]=1;
	dp[0][2]=0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] * 25 % mod  + dp[i - 1][1] * 24 % mod + dp[i - 1][2] * 25 % mod) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
		dp[i][2] = dp[i - 1][1];//"(i-2)tx"="(i-3)t"+'x'
	}
	//不含txt子串的情况总数sum
	ll sum=(dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % mod;

	cout << (ans-sum+mod)%mod << "\n";
	return ;
}
//
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
//		freopen("E:\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
//	cin >> t;
	while (t--) {
		slove();
	}
	return 0;
}

/*

  txt
  3

  .txt
  txt.
  4
  2*26

  .txt. x
  txt..
  ..txt
  .txt.
  5
  3*26*26

  txt...
  ..txt. x
  .txt.. x
  .txt..
  ...txt
  ..txt.
  6
  4*26*26*26

  txt....
  .txt... x
  ...txt. x
  ..txt.. x
  .txt...
  ..txt..
  ....txt
  ...txt.
  7
  5*26^4

 */
