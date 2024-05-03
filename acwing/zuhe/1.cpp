#include <iostream>
typedef long long ll;
const ll N = 10, mod = 1e9 + 7;
using namespace std;

int c[N][N];//i个里面选j个组合

void init()
{
	//实际意义为0个元素中选出0个元素进行组合，有1种选法
	for (int i = 0; i < N; i++)//需要先给C(0, 0)赋值为1
	{
		for (int j = 0; j <= i; j++)
		{
			if (!j)
				c[i][j] = 1;//选c(0,i)个都为1
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
