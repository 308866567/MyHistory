#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 10;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//ŷ����ʽ
//res��ʾ1~n����n���ʵĸ���
//res=n*(���(pi-1)/p1)
//���ȣ� ŷ��������һ�����Ժ�������m,n����ʱ����(mn)=��(m)?��(n)
ll phi(ll x)
{
	ll res = x;
	for (int i = 2; i <= x / i; i++)//Լ���ɶԳ���,i*i<=x
	{
		if (x % i == 0)//x�ֽ�������
		{
			res = res / i * (i - 1);//ŷ����ʽ
			while (x % i == 0)//��ȡ���������
				x /= i;
		}
	}
	if (x > 1) res = res / x * (x - 1);
	return res;
}
int main()
{
	//	fre;
	fast;
	int n;
	cin >> n;
	while (n -- )
	{
		int x;
		cin >> x;
		cout << phi(x) << endl;
	}
	return 0;

	return 0;
}
