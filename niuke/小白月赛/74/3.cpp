#include <iostream>
#include <unordered_map>
typedef long long ll;
const ll N = 2e3 + 1;
using namespace std;

int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	int t;
	int n, m;
	int col;
	while (t--)
	{
		cin >> n >> m;
		unordered_map<int, bool> ans;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> col;
				ans[col] = 1;
			}
		}
		cout<<ans.size()<<"\n";
	}
	return 0;
}
