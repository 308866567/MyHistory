#include <iostream>
typedef long long ll;
const ll N = 10, mod = 1e9 + 7;
using namespace std;

int c[N][N];//i������ѡj�����

void init()
{
	//ʵ������Ϊ0��Ԫ����ѡ��0��Ԫ�ؽ�����ϣ���1��ѡ��
	for (int i = 0; i < N; i++)//��Ҫ�ȸ�C(0, 0)��ֵΪ1
	{
		for (int j = 0; j <= i; j++)
		{
			if (!j)
				c[i][j] = 1;//ѡc(0,i)����Ϊ1
			else
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1] % mod;
			cout << c[i][j] << ' ';
		}
		cout << "\n";
	}
}

int main()
{
	//freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	return 0;
}
