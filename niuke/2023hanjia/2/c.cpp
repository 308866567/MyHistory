#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define T int 
typedef pair<T, T> pii;
typedef tuple<T, T, T> tii;

#define mp        make_pair
#define pb        push_back
#define mt        make_tuple
#define all(x)    (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))

inline T rd() {
	T x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 400007
#define mod 998244353

int cnt[N], l[N], r[N];

int main() {
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	int n = rd(), m = rd();
	for (int i = 1; i <= m; ++i) {
		l[i] = rd(); r[i] = rd();
		++cnt[l[i]]; --cnt[r[i] + 1];//前缀和标记
	}
	for (int i = 1; i < N; ++i) cnt[i] = (cnt[i] + cnt[i - 1]) % mod;
	for (int i = 1; i < N; ++i) cnt[i] = (cnt[i] + cnt[i - 1]) % mod;
	//算2遍前缀和
//	for (int i = 1; i <= n; ++i) printf("cnt[%d] = %d\n", i, cnt[i]);
	ll ans = 0;
	for (int i = 1; i <= m; ++i) //每次固定一个区间,匹配所有情况,然后减去区间自选
	{
		int R = n - l[i];//右边界
		int L = max(1, n - r[i]);//左边界
		//R+L等于n
		//printf("%d %d\n", L, R);
		if (L > R) continue;
		ans = (ans + cnt[R] - cnt[L - 1] + mod) % mod;//cnt[R] - cnt[L - 1],区间内所有情况的和
//		 printf("sum=%lld\n", ans);
		ans = (ans + mod - max(0, min(R, r[i]) - max(L, l[i]) + 1)) % mod;//自选的情况
//		printf("%lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
}
