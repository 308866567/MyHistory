#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 12 + 10;

#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#include<cmath>
//
ll g[N][N];
ll p()
{
	ll w = 0;
	ll n = 10;
	for (int i = 10; i >= 2; i -= 2)
	{
		w++;
		for (int j = 0; j < i; j++)
		{
			g[w][w + j] = w;
			g[11 - w][w + j] = w;
			g[w + j][w] = w;
			g[w + j][11 - w] = w;
		}
	}
	/*
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<g[i][j]<<" ";
		}
	cout<<"\n";
	}

	*/
	return 1;
}
ll slove()
{
	ll ans = 0;
	string x;
	for (int i = 1; i <= 10; i++)
	{
		cin >> x;
		//cout<<x<<"\n";
		for (int j = 0; j < 10; j++)
		{
			//	cin>>g[i][j];
			if (x[j] == 'X') ans += g[i][j + 1];
		}
	}
	return ans;
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	p();
	while (t--)
	{
		cout <<
		     slove() << "\n"
		     ;
	}

	return 0;
}

