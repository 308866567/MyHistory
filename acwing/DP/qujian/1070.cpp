#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 100 + 5;
int dp[N][N] = {};
string arr;
int n ;
void out()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << "\n";
	}
}
//�ж����ַ��Ƿ�ƥ��
bool f(char a, char b)
{
	if (a == '(' && b == ')')return 1;
	else if (a == '[' && b == ']') return 1;
	return 0;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// freopen("C:\\Users\\30886\\Desktop\\out.txt", "r", stdout);
	//  ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	cin >> arr;
	n = arr.size();
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1; //�������Ŷ�Ϊ1
	}
	for (int len = 2; len <= n; len++)
	{
		for (int l = 0; l + len - 1 < n; l++)
		{
			int r = l + len - 1;
			dp[l][r] = 300;
			//����ڶ�����������
			if (f(arr[l], arr[r]))//�����βƥ����
			{
				if (len == 2) 
					dp[l][r] = 0;
				else
					dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
			}
			//û��ƥ����
			//ö�ټ�ϵ�,���������ֶ�ΪGBE�����
			//������dp[i][j-1]��dp[j][j]�����
			for (int k = l; k < r; k++)
			{
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
//			printf("%d-%d=%d\n",l,r,dp[l][r]);
		}
	}
//	out();
	cout << dp[0][n - 1];
	return 0;
}
