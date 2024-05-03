#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1010;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n;
ll m, k;
ll p[N];
unordered_map<ll, bool> d[N];
ll find(ll x) {
	if (p[x] != x) // 根节点的父节点是其本身
		p[x] = find(p[x]);
	return p[x];
}

void slove() {
	cin >> n;
	cin >> m >> k;
	rep(i, 1, n)
	p[i] = i;
	ll a, b, c;
	rep(i, 1, m) {
		cin >> a >> b >> c;
		//朋友
		if (c == 1) {
			ll pa = find(a);
			ll pb = find(b);
			if (pa != pb)
				p[pa] = pb;
		} else {
			d[a][b] = 1;
			d[b][a] = 1;
		}
	}
	rep(i, 1, k) {
		cin >> a >> b;
		ll pa = find(a);
		ll pb = find(b);
//		cout<<pa<<' '<<pb<<"---";
		if (pa == pb) {
			if (d[a][b]) {
				cout << "OK but...\n";
			} else {
				cout << "No problem\n";
			}
		} else if (pa != pb && !d[a][b]) {
			cout << "OK\n";
		} else if (pa != pb && d[a][b]) {
			cout << "No way\n";
		}
	}
	return;
}
int main() {
#ifdef LOCAL
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--) {
		slove();
	}
	return 0;
}



//快读
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}


inline ll read1() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '0') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}


