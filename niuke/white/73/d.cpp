#include <iostream>
typedef long long ll;
const ll N = 10;//2e5+3;
using namespace std;
ll dp[N];
ll dp0[N] = {0}; //��ѧ������
ll t;
ll n, k;
ll ans = 0;
ll f(ll &x, ll i) //����x��ĩβ0����
{
	ll s = 0;
	while (x % 10 == 0)
	{
		x /= 10;
		s++;
		dp0[i]++;
	}
	return s;
}
//dp[i][j]��ʾi-jǰ׺�˵�0�ĸ���
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> dp[i];
			f(dp[i], i);//�����������
		}
		for (int i = n; i > 0; i--)
		{
			for (int j = n; j >= i; j--)
			{
				if (i != j)
				{
					//���
					dp[j] *= dp[i]; //����dp[j]
					dp0[j] += dp0[i];
				}
				//ͳ��0
				f(dp[j], j);//����˺��dp[j]
				if (dp0[j] == k)
					ans++;
			}
//			for (int k = 1; k <= n; k++)
//			{
//				cout << dp[k] << ' ';
//			}
//			cout << "\n";
//			for (int k = 1; k <= n; k++)
//			{
//				cout << dp0[k] << ' ';
//			}
//			cout << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}
