#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N = 2010, mod = 1e9 + 7;
int c[N][N];
void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}

int main()
{
	//	fre;
	fast;
	return 0;
}
