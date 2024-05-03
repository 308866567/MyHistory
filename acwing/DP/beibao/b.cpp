#include <iostream>
#include<deque>
#include<cstring>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
ll dir[8][2] =
{
2,-1,  2,1,  -2,-1,  -2,1,  1,2,  1,-2 , -1,2,  -1,-2
};
ll g[9][9];
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
} s, e;
void bfs()
{
	deque<node> q;
	deque<ll> size;
	q.push_back(s);
	size.push_back(0);
	ll n = 8;
	while (!q.empty())
	{
		node &head = q.front();
		ll s = size.front();
		if (head.x == e.x && head.y == e.y)
		{
			cout << s;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			ll x = head.x + dir[i][0];
			ll y = head.y + dir[i][1];
			if (x > 0 && y > 0 && x <= 8 && y <= 8 && g[x][y] == 0)
			{
				q.push_back(node(x, y));
				size.push_back(s + 1);
				g[x][y] = s;
			}
		}
		q.pop_front();
		size.pop_front();
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << g[i][j] << ' ';

		}
		cout << "\n";
	}
}

int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	string t;
	cin >> t;
	s.set(t[0] - 'a', t[1] - '0');
	cin >> t;
	e.set(t[0] - 'a', t[1] - '0');
	bfs();
	return 0;
}
