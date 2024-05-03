#include <iostream>
#include<deque>
#include<cstring>
#include<vector>
typedef long long ll;
const ll N = 1e3 + 21;
using namespace std;
ll n, m;
ll dir[5][2] =
{
	//下0左1右2上3
	1, 0,    0, -1,   0, 1,   -1, 0
};
string g[N];
bool used[N][N];
int path[N][N];
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
ll f(ll t)
{
	switch (t)
	{
		case 0:
			return 3;
		case 1:
			return 2;
		case 2:
			return 1;
		case 3:
			return 0;
	}
}

char toChar(ll t)
{
	switch (t)
	{
	case 0:
		return 'D';
	case 1:
		return 'L';
	case 2:
		return 'R';
	case 3:
		return 'U';
	}
}
void bfs(node s)
{
	deque<node> q;
	deque<ll> d;
	q.push_back(s);
	d.push_back(0);
	ll minn = 0;
	while (!q.empty())
	{
		node head = q.front();
		ll dd = d.front();
		if (head.x == e.x && head.y == e.y)
		{
//			cout << dd << "\n";
			minn = dd;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			ll x =	head.x	+ dir[i][0];
			ll y = head.y + dir[i][1];
			if (x >= 0 && y >= 0 && x < n && y < m  && used[x][y] == 0 && g[x][y] == '0')
			{
				q.push_back(node(x, y));
				d.push_back(dd + 1);
				path[x][y] = i;
				used[x][y] = 1;
			}
		}
		q.pop_front();
		d.pop_front();
	}

	ll n = 30,m=50;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout<<f(path[i][j])<<' ';
////			cout << path[i][j] << ' ';
//		}
//		cout << "\n";
//	}
	vector<int> ans;
	//从结尾回溯
	node now=e;
	ll ne;
	for (int i = 1; i <= minn; i++)
	{
		ans.push_back(path[now.x][now.y]);
		ne=f(ans.back());
		now.x+=dir[ne][0];
		now.y+=dir[ne][1];
	}
	for(int i=ans.size()-1;i>=0;i--)
	{
		cout<<toChar(ans[i]);
	}
	cout<<"\n";
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	n = 30, m = 50;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
	}
	s.set(0, 0);
	e.set(n - 1, m - 1);
	bfs(s);
	return 0;
}
