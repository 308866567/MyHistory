#include <iostream>
#include<deque>
#include<cstring>
typedef long long ll;
const ll N = 1e3 + 21;
using namespace std;
ll n;
ll dir[5][2] =
{
	1, 0,  -1, 0,   0, 1,   0, -1
};
string g[N];
bool used[N][N];
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
ll ans = 0;
void bfs(node s)
{
	deque<node> q;
	deque<ll> d;
	q.push_back(s);
	d.push_back(0);
	while (!q.empty())
	{
		node head = q.front();
		ll dd = d.front();
		if (head.x == e.x && head.y == e.y)
		{
			cout << dd;
			return ;
		}
		for (int i = 0; i < 4; i++)
		{
			ll x =	head.x	+ dir[i][0];
			ll y = head.y + dir[i][1];
			if (x >= 0 && y >= 0 && x < n && y < n  && used[x][y] == 0 && g[x][y] == '0')
			{
				q.push_back(node(x, y));
				d.push_back(dd + 1);
				used[x][y] = 1;
			}
		}
		q.pop_front();
		d.pop_front();
	}
}

int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	cin >> n ;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
	}
	ll a, b;
	cin >> a >> b;
	s.set(a-1, b-1);
	cin >> a >> b;
	e.set(a-1, b-1);
	bfs(s);
	return 0;
}
