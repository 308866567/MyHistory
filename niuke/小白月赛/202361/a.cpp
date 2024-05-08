#include <iostream>
#include<cstring>
typedef long long ll;
const ll N = 1e5 + 1;
using namespace std;
int ans = 0;
int n;
char x;
void f(string &t)
{
	int l=t.size();
	for (int k = 0; k < l; k++)
	{
		if (t[k] == x)
			ans++;
	}
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
//	freopen("C:\\Users\\30886\\Desktop\\out.txt", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> x;
	cin >> n;
	if (x == '*' || x == '=' || x == ',')
	{
		cout << (1 + n)*n / 2;
		return 0;
	}
	else
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
			{
				string 	t1 = to_string(j) ;
				string	t2 = to_string(i) ;
				string t3 = to_string(i * j);
//				cout << t;
				f(t1);
				f(t2);
				f(t3);
//			printf("%d*%d=%d,", j, i, i * j);
			}
	}
	cout << ans;
	return 0;
}
