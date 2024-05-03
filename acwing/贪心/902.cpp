#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>


struct node {
	ll l, r;
	void set() {
		cin >> l >> r;
	}
	bool operator<(const node &b) {
		return r < b.r;
	}
} arr[N];


//贪心策略
//每个区间必须被覆盖到
//所以遍历每个区间
//聚焦于单个区间的选点中
//点选在区间右的优点是会尽可能的覆盖更多区间
//
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
//		freopen("E:\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i].set();
	}
	sort(arr + 1, arr + 1 + n);
	ll ans = 1;
	ll now = arr[1].r;
	for (int i = 2; i <= n; i++) {
		//选的点覆盖了
		if (now >= arr[i].l && now <= arr[i].r) {
			continue;
		}
		//选新的点
		else{
			now = arr[i].r;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

