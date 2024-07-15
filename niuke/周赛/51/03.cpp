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
double x,y,t,a,b,c;
void solve()
{
	cin>>x>>y>>t>>a>>b>>c;
	//x y/a/b c
	if(x<=t){
		printf("%.6lf",(100-x)/c);
	}
	double ans1=(100-t)/c+(x-t)/y;
	double ans2=(100-x)/b;
	printf("%.6lf",min(ans1,ans2));
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
