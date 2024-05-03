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
//返回层数
ll deep(ll x) {
	ll d = 0;
	while (x > 0) {
		x >>= 1;
		d++;
	}
	return d;
}
ll s[50] = {0, 1}; //每层节点数
ll ans[50]={0};
ll arr[50];
//返回左子树节点个数
ll ls(ll x) {
	int i;
	for ( i = 1; i <= 8; i++) {
		if (s[i + 1] > x) break;
	}
	ll size = s[i] / 2;
	x -= s[i];
	ll mid = (s[i] + 1) / 2;
	if (x > mid) {
		size += mid;
	} else {
		size += x;
	}
	return size;
}
void dfs(ll p, ll l, ll r) {
	//赋值根节点
	ans[p] = arr[r];
	if(r<=l )return ;
	ll lsize = ls(r - l + 1);
	dfs(2 * p, l, l + lsize - 1); //左孩子
	dfs(2 * p + 1, l + lsize , r - 1); //右孩子
}
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
//		freopen("E:\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 2; i <= 8; i++) {
		s[i] = (s[i - 1] + 1) * 2 - 1;
//		cout << s[i] << ' ';
	}
	ll n ;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dfs(1, 1, n);
	for (int i = 1; i <= n; i++) {
		cout<<ans[i]<<' ';
	}
}
