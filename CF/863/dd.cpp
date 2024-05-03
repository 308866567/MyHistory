#include "bits/stdc++.h"
using namespace std;
#define orz 0
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
int ri() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
	return x * f;
}
ll f[50];
void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	ll w = f[n], h = f[n + 1];

	ll sx = 1, sy = 1, ex = w, ey = h;
	bool ok = false;
	while(1) {
		ll a = (ex - sx + 1), b = (ey - sy + 1);
		if(a == 1 and b == 1) {
			ok = true;
			break;
		}
		if(a < b) {
			if(y <= ey - a) ey -= a;
			else if(y >= sy + a) sy += a;
			else {
				ok = false;
				break;
			}
		} else {
			if(x <= ex - b) ex -= b;
			else if(x >= sx + b) sx += b;
			else {
				ok = false;
				break;
			}
		}
	}
	puts(ok ? "YES" : "NO");
}

int main() {
	f[0] = f[1] = 1;
	for(int i = 2; i <= 49; i++) f[i] = f[i - 1] + f[i - 2];
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return orz;
}
