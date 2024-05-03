#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

ll a[N], b[N];
int main() {
	ll n;
	cin >> n;
	bool f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i]=a[i+1]-a[i];
	}
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i + 1]) {
			f = 1;
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		if (b[i] <= b[i+1]) {
			f = 1;
			break;
		}
	}
	if (f)
		cout << "No";
	else
		cout << "Yes";
}
