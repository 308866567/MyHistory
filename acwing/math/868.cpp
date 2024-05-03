#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1e6+10;
int primes[N], cnt=0;
bool st[N];//1表示不是质数
void get_primes(int n)
{
	for (int i = 2; i <= n; i ++ )
	{
		if (!st[i]) primes[cnt ++ ] = i;
		for (int j = 0; i*primes[j] <= n ; j ++ )
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	get_primes(n);
	
	cout << cnt << endl;
	
	return 0;
}

