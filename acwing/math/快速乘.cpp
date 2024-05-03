#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
const ll mod = 10;

//o(1)
inline ll ksc(ll x, ll y, ll p)
{
	//a*b%mod=a%mod*b%mod
	//x%mod=x-floor(x/mod)*mod
	//ullһ���Զ�������������ͣ������˾ͻ��Զ���Ϊ0��
	ll z = x / p * y;
	ll res = (unsigned ll)x * y - (unsigned ll)z * p;
	return (res + p) % p;
}

//o(log2n)
inline ll ksc2(ll x, ll y, ll p) //����x��y�Ļ�
{
	ll res = 0; //�ӷ���ʼ��
	while (y)
	{
		if (y & 1)res = (res + x) % p; //ģ�¶�����
		x = (x << 1) % p;
		y >>= 1; //��x���ϳ�2�ﵽ������
	}
	return res;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	return 0;
}
