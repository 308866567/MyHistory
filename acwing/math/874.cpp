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
		if (!st[i]) //i������
		{
			primes[cnt++] = i;
			euler[i] = i - 1;//��1���κ���������������
		}
		for (int j = 0; primes[j] <= n / i; j++)
		{
			int t = primes[j] * i; //����
			st[t] = true;
			//i % primes[j] == 0ʱ��primes[j]��i����С������
			//����-1�Ѿ��������
			if (i % primes[j] == 0)
			{
				euler[t] = euler[i] * primes[j];
				break;
			}
			euler[t]=euler[i]*(primes[j]-1);
			//t�ɷֽ�Ϊi*��j������
			//euler[i]��֪
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

