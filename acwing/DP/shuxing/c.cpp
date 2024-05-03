
#include <iostream>

typedef long long ll;

ll extEuclidean(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	
	ll d = extEuclidean(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

ll findSolutionCount(ll n) {
	ll count = 0;
	
	for (ll A = 1; A <= n; A++) {
		ll x, y;
		ll d = extEuclidean(A, n, x, y);
		
		if (d == 1) {
			ll B = x;
			ll D = n / d;
			
			if (D > 0) {
				ll C = (n - A * B) / D;
				
				if (C > 0)
					count++;
			}
		}
	}
	
	return count * 4;
}

int main() {
	ll n;
	std::cout << "请输入正整数 n：" << std::endl;
	std::cin >> n;
	
	ll solutionCount = findSolutionCount(n);
	std::cout << "方案数: " << solutionCount << std::endl;
	
	return 0;
}
