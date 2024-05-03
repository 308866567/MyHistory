#include <iostream>
#include<deque>
#include<cstring>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
ll n, m;
ll dir[5][2] =
{
	1, 0,  -1, 0,   0, 1,   0, -1
};
string g[102];
bool used[102][102];
struct node
{
	ll x, y;
	node()
	{
	}
	node(ll a, int b)
	{
		x = a;
		y = b;
	}
	void set(ll a, int b)
	{
		x = a;
		y = b;
	}
} ;
ll ans = 0;
void bfs(node s)
{
	deque<node> q;
	q.push_back(s);
	while (!q.empty())
	{
		node head = q.front();
		for (int i = 0; i < 4; i++)
		{
			ll x =	head.x	+ dir[i][0];
			ll y = head.y + dir[i][1];
			if (x >= 0 && y >= 0 && x < n && y < m && used[x][y] == 0 && g[x][y] >'0')
			{
				q.push_back(node(x, y));
				used[x][y] = 1;
			}
		}
		q.pop_front();
	}
}

int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (used[i][j]||g[i][j]=='0')
				continue;
			ans++;
//			cout<<i<<' '<<j<<"\n";
			bfs(node(i, j));
		}
	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout<<used[i][j]<<' ';
//		}
//		cout<<"\n";
//	}
	cout << ans;
	return 0;
}
