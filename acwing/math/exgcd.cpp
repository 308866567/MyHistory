#include <iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 1;
unordered_map<ll, unordered_map<ll, ll>> g;
ll exgcd(ll a, ll b, ll &x, ll &y) //�������Լ��
{
	//��ax+by=gcd(a,b)��һ���(x1,y1)
	if (!b)
	{
		//�߽����,��b=0ʱ,
		//ʼ���н�Ϊ(1,0)
		//1*a+0*b=a=gcd(a,0)
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, x, y);
	//ͨ��������ԭ���̵Ľ�(x1,y1)
	//2��ʾ�ײ�
	ll t = x;
	x = y;//x1=y2
	y = t - (a / b) * y;//y1=x2-(a/b)*y2
	return d;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll a = 24, b = 18, x = 0, y = 0;
//	cin >> a >> b;
	ll d = exgcd(a, b, x, y);
	cout << d << "\n";
	cout << x << " " << y << "\n";

	//���ax+by=k�Ľ�
	ll k;
	if (k % d == 0) //k�ܱ�gcd(a,b)�������н�
	{
		x = x * k / d;
		y = (k - a * x) / b;
	}
	else
	{
		cout << "�޽�";
	}
	return 0;
}
