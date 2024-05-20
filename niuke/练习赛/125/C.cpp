#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll cal(ll x)
{
	ll n = x;
	vector<ll> nums;
	ll p = 1;
	while (n)
	{
		nums.emplace_back(n % 10);
		n /= 10;
		if (n == 0) break;
		p *= 10;
	}
	return x % p + x / 10;
}

ll f[20][11][11];
ll dp(ll y)
{
	memset(f, 0, sizeof f);
	vector<ll> nums;//0是低位
	//条件:(低位+高位)%10=y[低位]
	ll n = y;
	while (n)
	{
		nums.emplace_back(n % 10);
		n /= 10;
	}
	ll len = nums.size() - 1;
	f[1][nums[len]][0] = 1;
	rep(i, 1, nums.size())
	{
		rep(j, 0, 9)
		{
			rep(k, 0, 9)
			{
				//当前为f[i][j][k]
				//更新f[i+1][][]
				//首位填a
				//a满足与
				rep(a, 0, 9)
				{
					if ((a + j) / 10 == nums[len - 1])
						f[i + 1][(a + k) % 10][(a + k) / 10]
						+= f[i][j][k];
				}
			}
		}
		len--;
	}
	ll sum = 0;
	rep(i, 0, 9)
	{
		sum += f[nums.size() + 1][nums[0]][i];
	}
	return sum;
}
void solve()
{
	ll y;
	cin >> y;
	cout << dp(54321) << "\n";
}


int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
	freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
//	rep(i,1,100){
//		cout<<cal(i)<<"\n";
//	}
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
