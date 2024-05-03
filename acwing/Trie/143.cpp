#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const long long N = 100010;
const long long M = 3100010;
int son[M][3],  idx;
int arr[N];
void insert(ll x)
{
	int p = 0;
	for (int i = 30; i >=0; i -- )
	{
		int u = (x>>i)&1;
		if (!son[p][u])
			son[p][u] = ++ idx;
		p = son[p][u];
	}
}
ll search(ll x)//x与其他数异或
{
	ll sum = 0;
	int p = 0;
	for (int i = 30; i >=0; i -- )
	{
		int u = (x>>i)&1;
		if (son[p][!u]!=0)//第i位可以取1
		{
			p = son[p][!u];
			sum+=(1<<i);//加上2的i次方
		}
		else 
		{
			p = son[p][u];
		}
	}
	return sum;
}
int main()
{
	//	fre;
	// 	fast;
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		insert(arr[i]);
	}
	ll ans = -1;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, search(arr[i]));
	}
	cout<<ans;
	return 0;
}
