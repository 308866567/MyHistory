#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e9 + 7;
int main()
{
	//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll n, a;
	ll ans = 1;
	unordered_map <ll, ll> u;
	cin >> n;
	while (n--)
	{
		cin >> a;
		//a�ֽ�������,��
		for (ll i = 2; i <= a / i; i++)
		{
			while (a % i == 0)
			{
				a /= i;
				u[i]++;
			}
		}
		if (a > 1)
			u[a]++;
	}
	//��a=b*c
	//����b��a����������϶���,c����b���ʣ�µ����������,���Բ��ù�c
	//����ÿ��������,��0,1,2...��ѡ��
	//ÿ�����ӵ�ѡ����˼�Ϊ����ȵ�b������
	//��*2����ΪԼ����һһ��Ӧ��,���b��������е����
	for (auto it : u)
	{
		ans = ans * (it.second + 1) % N;
	}
	cout << ans;
	return 0;
}
