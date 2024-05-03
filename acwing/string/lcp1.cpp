#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 10;
unordered_map<ll, unordered_map<ll, ll>> g;
//
class hou
{
		string ch;
		ll sa[N], a[N], t[N], c[N], n, m = 30, p;
		void slove()
		{
			cin >> ch;
			for (int i = 0; i < n; i++)//以第一个字符为关键字排序
			{
				a[i] = (ch[i] - 'a' + 1);//
				c[a[i]]++;
			}
			for(int i=1;i<m;i++) c[i]+=c[i-1];
			for(int i=n-1;i>=0;i--) sa[--c[a[i]]]=i;
		}
};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	return 0;
}
