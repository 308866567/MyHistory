#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 10;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//
//si表示与pi整除的数的集合
//求si的或集
//奇数交集-偶数交集
//求个数
ll n, m;
ll p[20];
int main()
{
		fre;
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
	}
	ll ans = 0;
	//二进制表示状态
	for (int i = 1; i < 1 << m; i++)
	{
		ll t = 1;//最小公倍数
		ll s = 0;
		//枚举当前状态每一位
		for (int j = 1; j <= m; j++)
		{
			if ((i >> (j - 1)) & 1)//属于集合sj
			{
				if (t * p[j] > n)
				{
					t = -1;
					break;
				}
				s++;
				t *= p[j];

			}
		}
		if (t == -1) continue;
		//交集大小为n/t
		if (s & 1) ans += n / t;//奇数个集合
		else ans -= n / t;
	}
	cout << ans;
	return 0;
}
