#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
typedef long long ll;
const ll N = 1000 + 1;
using namespace std;
bool graph[N][N] = {0};
bool vis[N] = {1};
struct T
{
	int h;
	int val;
	friend bool operator<(T &a, T &b)
	{
		if (a.h == b.h)
			return a.val < b.val;
		else
			return a.h < b.h;
	}
} h[N];
int n, m, s;
vector<int >ans[1001];
deque<int > q;
int sum = 0;
void bfs()
{
	//从点s出发
	//	vis[s] = 1;
	q.push_back(s);
	int now;
	while (!q.empty())
	{
		now = q.front();
		q.pop_front();
		
		
		if(vis[now]) continue;
		sum++;
		vis[now] = 1;
		if(sum==n) cout<<now;else
			cout << now << ' ';
		
		
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i] && graph[now][i])
			{
				q.push_back(i);
				if (h[i].h == 0)
					h[i].h = h[now].h + 1;
				else
					h[i].h = min(h[i].h, h[now].h + 1);
			}
		}
	}
	
}
int main()
{
		freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		h[i].val = i;
		h[i].h = 0;
	}
	h[s].h = 1;
	bfs();
		cout << "\n";
	sort(h + 1, h + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (h[i].h == 0) continue;
				cout << h[i].val << ' ';
	}
	if (sum < n) cout << 0;
	return 0;
}
