#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 1;
ll arr[N];

class BIT1//�����޸�,��ѯǰ׺��,���������״����
{
public:
	ll *A;
	ll t[N];
	BIT1(ll *x)
	{
		A = x;
		//			for (int i = 1; i <= n; i++)
		//			{
		//				cin >> arr[i];
		//				A.update(i, arr[i]);
		//			}
	}
	ll lowbit(ll x)
	{
		return x & (-x);
	}
	//�����޸�
	void update(ll x, ll k)
	{
		for (int i = x; i <= N; i += lowbit(i))
		{
			t[i] += k;
		}
	}
	
	//��ѯǰ׺��,��ѯ1-n�ĺ�
	ll query(ll x)
	{
		ll res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
		{
			res += t[i];
		}
		return res;
	}
	//�����ѯ,ʹ��ǰ׺���������
	//[l,r]=[1,r]-[1,l-1]
	ll query(ll l, ll r)
	{
		return query(r) - query(l - 1);
	}
	//��չ
	//�����޸�,����ʱ���ò��update(i,a[i]-a[i-1]);
	void update(ll l, ll r, ll k)
	{
		update(l, k);
		update(r+1, -k);
	}
	
};
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	BIT1 A(arr);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		A.update(i, arr[i]);
	}
	
	ll a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			A.update(b, c);
		}
		else
		{
			a = A.query(b, c);
			cout << a << "\n";
		}
	}
	
	
	return 0;
}
