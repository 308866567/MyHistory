#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
ll n;
const ll N = 20, P = 1e9 + 7;

struct F
{
	ll s0, s1, s2;
//个数
//和
//平方的和
} f[N][10][7][7];
//长度,最高位数字,%7的余数,各位数字和%7的余数

ll mod(ll x, ll y)
{
	return (x % y + y) % y;
}

int power7[N], power9[N];//10的i次方2%7的值,%P的值

void init()
{
	//长一位的情况
	rep(i, 0, 9)
	{
		if (i == 7) continue;
		auto &v = f[1][i][i % 7][i % 7];
		v.s0++;
		v.s1 += i;
		v.s2 += i * i;
	}

	ll power = 10; //当前的位权
	rep(i, 2, N - 1)
	{
		rep(j, 0, 9)
		{
			if (j == 7) continue;
			rep(a, 0, 7)
			{
				rep(b, 0, 7)
				{
					//用子状态更新主状态
					rep(k, 0, 9)//子状态的最高位
					{
						if (k == 7) continue;
						auto &v1 = f[i][j][a][b];//主状态
						auto &v2 = f[i - 1][k][mod(a - j * power, 7)][mod(b - j, 7)]; //子状态
						v1.s0 = mod(v1.s0 + v2.s0, P); //个数
						/*
							多了v2.s0个sum(jAi)
							jAi=j*power+Ai
						*/
						v1.s1 = mod(v1.s1
						            + v2.s1
						            + j * (power % P) % P * v2.s0
						            , P);

						/*
							多了v2.s0个sum(jAi*jAi)
							jAi*jAi=(j*power+Ai)*(j*power+Ai)
						  =j*power*j*power+2*j*power*Ai+Ai*Ai
						*/
						v1.s2 = mod(v1.s2 +
						            j * j * (power % P) % P * (power % P) % P * v2.s0
						            + v2.s2
						            + 2 * j * power % P * v2.s1
						            , P);

					}
				}
			}
		}
		power *= 10;
	}


	power7[0] = 1;
	for (int i = 1; i < N; i ++ )
		power7[i] = power7[i - 1] * 10 % 7;

	power9[0] = 1;
	for (int i = 1; i < N; i ++ )
		power9[i] = power9[i - 1] * 10ll % P;
}

ll dp(ll n)
{
	if (!n)	return 0;
	ll res = 0;
	vector<ll> nums;
	while (n) nums.emplace_back(n % 10), n /= 10;
	ll last_a = 0; //数本身
	ll last_b = 0; //数位和
	rrep(i, nums.size() - 1, 0)
	{
		ll x = nums[i];
		//当前位填j
		rep(j, 0, x - 1)
		{
			if(j==7) continue;
			//加上子状态的平方和,i+1,j,%7余数!=0,数位和!=0
			//i+1,j,last_a*10+j+k,last_b+j+k

		}


		if (x == 7 ) break;
		last_a = last_a * 10 + x;
		last_b += x;
		if (!i) res++;
	}
	return res;
}

void solve()
{
	ll l, r;
	cin >> l >> r;
	cout << mod(dp(r) - dp(l - 1), P) << "\n";
}


int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	cin >> t;
	init();
	while (t--)
	{
		solve();
	}
	return 0;
}
