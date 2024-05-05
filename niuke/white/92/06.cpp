#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f

	ll n,m;
	vector<ll> w(1e5+2), v(1e5+2);
void solve()
{

	cin >> n>>m;

	rep(i,0,n-1){
		cin>>w[i];
	}
	rep(i,0,n-1){
		cin>>v[i];
	}
	ll x;
	map<ll,ll> g;
	rep(i,0,m-1){//一只一只羊来进行标记
		cin>>x;
		ll d=0;
		rep(j,0,n-1){
			g[d-x]+=v[j];//当偏移量>=这儿时,+=v[j]
			d+=w[j];
			g[d-x]-=v[j];//当偏移量超过时,-=v[j]
		}
	}
	//差分思想
	//遍历一遍得到情况
	set<ll> s;
	ll sum=0;
    //从小到大遍历key才能得出正确答案
	for(auto it:g){
		sum+=it.second;
//         cout<<sum<<' ';
		s.insert(sum);
	}
//     cout<<"\n";
//     for(auto it: s){
//         cout<<it<<' ';
//     }
	cout<<s.size();
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
// 快读
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
