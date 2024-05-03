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
		++cnt[l[i]]; --cnt[r[i] + 1];//ǰ׺�ͱ��
	}
	for (int i = 1; i < N; ++i) cnt[i] = (cnt[i] + cnt[i - 1]) % mod;
	for (int i = 1; i < N; ++i) cnt[i] = (cnt[i] + cnt[i - 1]) % mod;
	//��2��ǰ׺��
//	for (int i = 1; i <= n; ++i) printf("cnt[%d] = %d\n", i, cnt[i]);
	ll ans = 0;
	for (int i = 1; i <= m; ++i) //ÿ�ι̶�һ������,ƥ���������,Ȼ���ȥ������ѡ
	{
		int R = n - l[i];//�ұ߽�
		int L = max(1, n - r[i]);//��߽�
		//R+L����n
		//printf("%d %d\n", L, R);
		if (L > R) continue;
		ans = (ans + cnt[R] - cnt[L - 1] + mod) % mod;//cnt[R] - cnt[L - 1],��������������ĺ�
//		 printf("sum=%lld\n", ans);
		ans = (ans + mod - max(0, min(R, r[i]) - max(L, l[i]) + 1)) % mod;//��ѡ�����
//		printf("%lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
}
