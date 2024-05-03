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


/*
  假设按（）分成了ans组
  存在cnt<ans,怎么调整ans？
  
  
*/
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
		if (arr[i].l > now) {
			ans++;
			now = arr[i].r;
		} else {
			continue;
		}
	}
	cout << ans;
	return 0;
}

