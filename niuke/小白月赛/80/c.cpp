#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>
ll n, m, k;
ll ban[N];
ll slove(ll x) {
	if (k < ban[x])
		return -1;
	else if (k == ban[x]) {
		for (int i = 1; i <= m; i++) {
			if (x == i)
				continue;
		}
	}
	
}

int main() {
	freopen("D:\\in.txt", "r", stdin);
	cin >> n >> m >> k;

	//已经走了k名学生
	ll t;
	for (int i = 1; i <= n; i++) {
		//学生i属于哪个班级
		cin >> t;
		ban[t]++;
	}
	//输出只有班级i拖堂，且走了k个，剩下
	for (int i = 1; i <= m; i++) {
		slove(i);
	}
	return 0;
}
