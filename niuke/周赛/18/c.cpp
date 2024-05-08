#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

unordered_map<ll, ll> g;
//
//1 2 3 5 7
//4 6 8 9 10
//2 0
//3 0
//4
ll ans = 0;
ll n;
ll k;
ll a[N];
bool user[N];
int main() {
// 	freopen("E:\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= k;
	}
	ll l = 1, r = n;
	sort(a + 1, a + 1 + n);
	a[r+1]=k+1;
	//
	while (a[l] == 0) {
		ans++;
		l++;
	}
	
	//a[l]=a a[r]=b
	//a+b=k
	//b=k-a
	//<(k-a)就不找
	for (; l < r; l++) {
		while(a[r]>(k-a[l]) &&l<r){
			r--;
		}
		if(a[r]+a[l]==k){
			ans++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
