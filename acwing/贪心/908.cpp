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
选取最大的区间数量
a b两区间l相同 选r小的
a b的l不同,选l小的？会出现r很大
a b的r相同，选l小的
r不同，选r小的

假设存在一个最优解，
其中选择的区间不是按照右端点最小的顺序选择的，而是按照某种其他规则。
  
但是我们可以通过交换这些区间的顺序，
将它们按照右端点最小的顺序排列
，这不会改变它们之间的相交关系。

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

