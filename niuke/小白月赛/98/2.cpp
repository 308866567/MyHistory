#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n;
ll a[N];
void solve()
{
	cin >> n;
    ll j=0,o=0;
    rep(i,1,n){
        cin>>a[i];
        if(a[i]&1) j++;
        else o++;
    }
    //奇数+偶+偶
    //奇数*奇数*奇数
    ll ans=n;
    if(ans<=2){
        cout<<ans<<"\n";
        return ;
    }
    if(j>=o){
        ans-=o;
        j-=o;
        if(j&1){
            ans-=(j-1);
        }else{
            ans=0;
        }
    }
    else{
        ans-=j;
    }
    cout<<ans<<"\n";
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
