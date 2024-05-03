#include <iostream>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	int x;
	int a[] = {2, 3, 5, 7};
	cin >> x;
	for (int i = 0; i < 4; i++)
	{
		if (x % a[i] == 0)
		{
			cout << "YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
