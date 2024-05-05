 




#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n;
ll a[N];
ll x;
void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		cin >> a[i];
	}
	cin >> x;
	ll ans=0;
	sort(a+1,a+1+n);
	ll c=1;//分裂基数
	ll L=x,R=x;//边界
	for(ll l=1,r=n;l<=n;c*=2){
        r=n;
		while(l<=n&&a[l]<L){
			l++;
		}
		while(r>0&&a[r]>R){
			r--;
		}
// 		cout<<l<<" "<<r<<"\n";
		ans=max(ans,(r-l+1)*c);
		L=L*3-2,R*=3;
	}
	cout << ans;
	return;
}
int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
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
