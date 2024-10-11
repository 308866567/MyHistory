#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;

//https://www.acwing.com/file_system/file/content/whole/index/content/4184000/
ll n;
ll w[N];
ll f[N][2];//1表示持有
/*
第N天 已经交易X次(以sell为1次) 当前是否持有股票(0否1真) 
表示这种情况下的最大收益
int dp[N][2][2];
*/
void solve()
{
    cin>>n;
    rep(i,1,n){
        cin>>w[i];
    }
    f[1][0]=0,f[1][1]=-w[1];
    //允许多次交易
    rep(i,2,n){
        f[i][1]=max(f[i-1][1],f[i-1][0]-w[i]);
        f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
    }
    cout<<max(f[n][1],f[n][0])<<"\n";
}

int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
	freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
	// ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

//  "-Wl,--stack=134217728",
//ulimit -s 134217728
#include <sys/resource.h>
void add()
{
    const rlim_t kStackSize = 64 * 1024 * 1024; // min stack size = 16 MB
    struct rlimit rl;
    int result;
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
}