#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
ll n = 23333333;

//11027421
double f(double s0)
{
	double s1 = n - s0;
	// double p0 = s0 * (s0 / n);
	// double p1 = s1 * (s1 / n);
	return -(s1 * s1 / n * log(s1 / n) / log(2) + s0 * s0 / n * log(s0 / n) / log(2));
}
int main()
{
	freopen("/home/xiaobingdu/Downloads/in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i <=23333333; i++)
	{
		double sum = f(i);
		if (sum > 11625907.5 && sum < 11625907.6)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}