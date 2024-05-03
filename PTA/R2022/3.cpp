#include <iostream>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
int t = 0;
string arr;
bool ans1, ans2;
void slove()
{
	ans1 = 1;
	ans2 = 1;
	int n = arr.size();
	if (arr[0] == 'V')
		ans2 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == 'N')
		{
			if (arr[i + 1] == 'N')
			{
				ans1 = 0, ans2 = 0;
				break;
			}
		}
	}
	cout << ans1 << ' ' << ans2;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> arr;
		slove();
		if (t > 0)
			cout << "\n";
	}
	return 0;
}
