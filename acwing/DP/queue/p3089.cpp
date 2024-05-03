#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>

ll n;
ll f[N];
struct node
{
	ll	x, p;
	operator <(node & t)
	{
		return x < t.x;
	}
} a[N];

void slove1()
{
	ll maxx = -1;
	for (int i = 1; i <= n; i++)
	{

	}
	cout << maxx;
	return ;
}

int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n ;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].p;
	}
	sort(a + 1, a + n + 1);

	slove1();
	return 0;
}

