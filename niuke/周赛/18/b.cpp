#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

unordered_map<ll, unordered_map<ll, ll>> g;
//
//1 2 3 5 7
//4 6 8 9 10
//2 0
//3 0
//4
ll ans = 0;
ll n;
ll arr[12];
bool used[11];
bool st[30];//0为素数
bool init(ll x){
	for(int i=2;i<=x;i++){
		if(st[i]) continue;
		for(int j=i+i;j<=x;j+=i){
			st[j]=1;
		}
	}
	return 0;
}
void dfs(ll now) {
	if (now > n) {
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]){
			continue;
		}
		used[i]=1;
		arr[now]=i;
		if(now==1||st[i+arr[now-1]])
			dfs(now+1);
		used[i]=0;
	}
}
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	init(25);
	dfs(1);
	cout<<ans;
	return 0;
}
