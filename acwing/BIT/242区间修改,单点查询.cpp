#include<iostream>
using namespace std;
//https://www.acwing.com/problem/content/248/
typedef long long ll;
static const ll N = 1e5 + 5; //���鳤��
ll n, m;
ll t[N], a[N];

//�����޸�,�����ѯ,��״����ά��һ���������
ll lowbit(ll x)
{
	return x & (-x);
}
//���ò��ʵ�������޸�
void update(ll x, ll k)
{
	for (int i = x; i <= N; i += lowbit(i))
	{
		t[i] += k;
	}
}
//��ѯa[x],�����ѯ,���b1+...bx��ֵΪa[x]
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
		update(i,a[i]-a[i-1]);//���ò��
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
			case 'C'://�����޸�
				cin >> a >> b >> c;
				update(a,c);
				update(b+1,-c);
				break;

		}
	}
	return 0;
}
