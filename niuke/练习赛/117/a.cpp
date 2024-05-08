#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>
ll n;
ll a[N];


int main() {
//	freopen("E:\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a + 1, a + n + 1);
		if (a[2] == a[n])
			cout << sum - a[1] - a[n];
		else if (sum == 0 )
			cout << 0;
		else
			cout << sum - a[1] - a[n] + 1;

		cout << "\n";
	}
	return 0;
}
