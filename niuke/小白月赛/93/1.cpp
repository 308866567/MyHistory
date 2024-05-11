#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
ll n;
ll a, k;
void solve()
{
	cin >> n >> a >> k;
	a++;
	rep(i,0,k-1){
		ll tt=a+i*n;
		string t=to_string(tt);
		if(tt%7==0||t.find('7')!=string::npos){
			cout<<"p ";
		}else{
			cout<<t<<' ';
		}
	}
	cout<<"\n";
}
int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
