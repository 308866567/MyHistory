#include <iostream>
#include<deque>
#include<cstring>
typedef long long ll;
const ll N = 2e5 + 31;
using namespace std;
ll n, k;
struct node
{
	ll x, t;
	node(ll a, int b)
	{
		x = a;
		t = b;
	}
};
void bfs()
{
	if(k<=n){
		cout<<n-k;
		return;
	}
	deque<node> q;
	q.push_back(node(n, 0));
	ll ans = 0x3f3f3f3f;
	while (!q.empty())
	{
		node &head = q.front();
		if (head.x == k)
		{
			if (head.t >= ans)
			{
				break;
			}
			ans = min(ans, head.t);
		}
		q.push_back(node(head.x + 1, head.t + 1));
		q.push_back(node(head.x - 1, head.t + 1));
		q.push_back(node(head.x << 1, head.t + 1));
		q.pop_front();
	}
	cout << ans << "\n";
}
ll f[N];
void solve()
{
	memset(f, 0x3f, sizeof f);
	f[n] = 0;
	for (int i = n -1; i >= 0; i--)
	{
		f[i] = f[i + 1] + 1;
		f[2*i]=min(f[2*i],f[i]+1);
	}
	for (int i = n ; i <= k; i++)
	{
		if(i%2==0)
			f[i]=min(f[i],min(f[i-1]+1,f[i/2]+1));
		else{
			f[i]=min(f[i],min(f[i-1]+1,f[i/2]+2));
			f[i]=min(f[i],f[(i+1)/2]+2);
		}
	}
//	for (int i = 1; i <= k; i++)
//	{
//		cout << f[i] << ' ';
//	}
//	cout << "\n";
	cout << f[k];
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	cin >> n >> k;
//	bfs();
	solve();
	return 0;
}
