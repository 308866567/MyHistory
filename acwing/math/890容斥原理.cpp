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
//
//si��ʾ��pi���������ļ���
//��si�Ļ�
//��������-ż������
//�����
ll n, m;
ll p[20];
int main()
{
		fre;
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
	}
	ll ans = 0;
	//�����Ʊ�ʾ״̬
	for (int i = 1; i < 1 << m; i++)
	{
		ll t = 1;//��С������
		ll s = 0;
		//ö�ٵ�ǰ״̬ÿһλ
		for (int j = 1; j <= m; j++)
		{
			if ((i >> (j - 1)) & 1)//���ڼ���sj
			{
				if (t * p[j] > n)
				{
					t = -1;
					break;
				}
				s++;
				t *= p[j];

			}
		}
		if (t == -1) continue;
		//������СΪn/t
		if (s & 1) ans += n / t;//����������
		else ans -= n / t;
	}
	cout << ans;
	return 0;
}
