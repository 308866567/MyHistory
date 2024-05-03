#include <iostream>
#include<deque>
#include<cstring>
typedef long long ll;
const ll N = 1e3 + 21;
using namespace std;
ll n, m;
ll dir[5][2] =
{
	1, 0,  -1, 0,   0, 1,   0, -1
};
string g[N];
ll ans[N][N];
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

deque<node> q;
deque<ll> size;
void bfs()
{

	while (!q.empty())
	{
		node head = q.front();
		ll d = size.front();
		for (int i = 0; i < 4; i++)
		{
			ll x =	head.x	+ dir[i][0];
			ll y = head.y + dir[i][1];
			if (x >= 0 && y >= 0 && x < n && y < m  && g[x][y] == '0'&&d+1<ans[x][y])
			{
				q.push_back(node(x, y));
				size.push_back(d+1);
				ans[x][y]=min(ans[x][y],d+1);
			}
		}
		q.pop_front();
		size.pop_front();
	}
}

int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	memset(ans,0x3f,sizeof ans);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ( g[i][j] == '0')
				continue;
			//			cout<<i<<' '<<j<<"\n";
			q.push_back(node(i,j));
			size.push_back(0);
			ans[i][j] = 0;
		}
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << "\n";
	}
	return 0;
}
