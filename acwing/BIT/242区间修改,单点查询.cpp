#include<iostream>
using namespace std;
//https://www.acwing.com/problem/content/248/
typedef long long ll;
static const ll N = 1e5 + 5; //数组长度
ll n, m;
ll t[N], a[N];

//区间修改,单点查询,树状数组维护一个差分数组
ll lowbit(ll x)
{
	return x & (-x);
}
//利用差分实现区间修改
void update(ll x, ll k)
{
	for (int i = x; i <= N; i += lowbit(i))
	{
		t[i] += k;
	}
}
//查询a[x],单点查询,差分b1+...bx的值为a[x]
ll query(ll x)
{
	ll res = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		res += t[i];
	return res;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(i,a[i]-a[i-1]);//利用差分
	}
	char t;
	ll a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		switch (t)
		{
			case 'Q':
				cin >> a;
				b = query(a);
				cout << b<<"\n";
				break;
			case 'C'://区间修改
				cin >> a >> b >> c;
				update(a,c);
				update(b+1,-c);
				break;

		}
	}
	return 0;
}
