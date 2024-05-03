#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e3 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

char s[N];
ll dp[N][N];

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin.getline(s,1005,'\n');
	ll ans = 1;
	//枚举中心
	for (int i = 0; i < 1005; i++) {
		if(s[i]=='\000') break;
		ll l = i, r = i;
		//以s[i]向左右搜索,不满足就返回
		while (l >= 0 && s[r]!='\000') {
			if (s[l ] == s[r ]) {
				ans = max(ans, r-l + 1);
				l--, r++;
			} else {
				break;
			}
		}
	}
	for (int i = 0; i < 1005; i++) {
		if(s[i]=='\000') break;
		if(s[i]!=s[i+1]) continue;
		ans=max(ans,(ll)2);
		ll l = i, r = i+1;
//以s[i]向左右搜索,不满足就返回
		while (l >= 0 && s[r]!='\000') {
			if (s[l ] == s[r ]) {
				ans = max(ans, r-l + 1);
				l--, r++;
			} else {
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
