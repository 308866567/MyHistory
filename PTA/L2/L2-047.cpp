#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll n, k, w;

unordered_map<ll, unordered_map<ll, ll>> f;
int main() {
	cin >> k; //k轮
	//败者能力值
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= 1 << (k - i); j++) {
			cin>>f[i][j];
		}
	}
	cin >> w;
	cout<<w;
}
