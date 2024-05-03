#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1000010;


int primes[N], cnt;
int euler[N];
bool st[N];


void get_eulers(int n)
{
	euler[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!st[i]) //i是质数
		{
			primes[cnt++] = i;
			euler[i] = i - 1;//除1外任何数都与质数互质
		}
		for (int j = 0; primes[j] <= n / i; j++)
		{
			int t = primes[j] * i; //倍数
			st[t] = true;
			//i % primes[j] == 0时：primes[j]是i的最小质因子
			//所以-1已经计算过了
			if (i % primes[j] == 0)
			{
				euler[t] = euler[i] * primes[j];
				break;
			}
			euler[t]=euler[i]*(primes[j]-1);
			//t可分解为i*第j个质数
			//euler[i]已知
		}
	}
}


int main()
{
	int n;
	cin >> n;

	get_eulers(n);

	LL res = 0;
	for (int i = 1; i <= n; i ++ ) res += euler[i];

	cout << res << endl;

	return 0;
}

