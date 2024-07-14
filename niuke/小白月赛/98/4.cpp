#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e3 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll L, R;
char a[N];
ll f[N][N];
ll s0[N],s1[N];
void solve()
{
    cin >> n >> L >> R;
    cin >> a + 1;
    // cout << a + 1;
    rep(i,1,n){
        if(a[i]=='0') s0[i]++;
        else s1[i]++;
        s0[i]+=s0[i-1];
        s1[i]+=s1[i-1];
    }
    for (ll len = 2; len <= n; len++)
    {
        for (ll l = 1; l + len - 1 <= n; l++)
        {
            ll r = l + len - 1;
            //k后切割
            for(ll k=l;k<r;k++){
                //合并条件,左0-右1在[L,R]里
                ll t=abs(s0[k]-s0[l-1]-(s1[r]-s1[k]));
                if(t>=L&&t<=R)
                    f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]+1);
            }
            // cout<<l<<"-"<<r<<"="<<f[l][r]<<"\n";
        }
    }
    cout<<f[1][n]<<"\n";
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
