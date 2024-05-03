#include <iostream>
#include <deque>
#include<cstring>
#include<unordered_map>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
deque<int> q;
int t;
int n;
unordered_map<ll,ll> f;
ll in[12];
ll out[12];
unordered_map<ll,ll> used;//是否已经输出过

bool slove()
{
	ll now = 0; //now之前的都入栈了
	for (int i = 0; i < n; i++)
	{
		if (used[out[i]])
		{
			return 0;//失败
		}
		//是否未入栈
		while (f[out[i]] >= now)
		{
			q.push_back(in[now]);
			now++;
		}
		//是否在栈里
		while (!q.empty())
		{
			if (q.back() == out[i])
			{
				used[q.back()] = 1;
				q.pop_back();
				break;
			}
			else
				q.pop_back();
		}
		if (used[out[i]] == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		used.clear();
		f.clear();
		q.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> in[i];
			f[in[i]]=i;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> out[i];
		}
		if (slove())cout << "Yes";
		else cout << "NO";
		if (t > 0)cout << "\n";
	}
	return 0;
}
