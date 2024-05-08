#include <iostream>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		int i = 1;
		while (1)
		{
			if (n - i < i+1)
			{
				cout << n << "\n";
				break;
			}
			cout << i << " ";
			n -= i;
			i++;
		}
//		cout<<n<<"\n";
	}
	return 0;
}
