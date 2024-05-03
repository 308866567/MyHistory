#include <iostream>
#include<cmath>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
int t;
double a, b, c;
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	cin >> t;
	double f;
	double ans1, ans2;
	while (t--)
	{
		cin >> a >> b >> c;
		f = b * b - 4 * a * c;
		if (f > 0)
		{
			ans1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
			ans2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
			printf("x1=%.5lf;", max(ans1, ans2));
			printf("x2=%.5lf", min(ans1, ans2));
		}
		else if (f == 0)
		{
			ans1=(-b ) / (2 * a)+0;
//			(-b + sqrt(b * b - 4 * a * c)) / (2 * a)
			printf("x1=x2=%.5lf;", ans1);
		}
		else
		{
			f = sqrt(-f);
			printf("x1=%.5lf+%.5lfi;", (-b ) / (2 * a)+0, (f) / (2 * a));
			printf("x2=%.5lf-%.5lfi", (-b ) / (2 * a)+0, (f) / (2 * a));
		}
		if (t > 0)cout << "\n";
	}
	return 0;
}
