#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n;
ll a[N];
void slove()
{
    priority_queue<ll> q;//默认大根
	cin >> n;
    ll sum=0;
    rep(i,1,n){
        cin>>a[i];
        sum+=a[i];
        q.push(a[i]);
    }
    //寄一次只能染出一种颜色,贪心染最贵的
    //12 + 7 + 4 + 2 
    ll ans=0;
    while (q.size()>1)
    {
        ll t=q.top();
        q.pop();
        ans+=sum;
        cout<<sum<<' ';
        sum-=t;
    }
    cout<<ans<<"\n";
	return;
} 

void slove2()
{
    priority_queue<ll,vector<ll>,greater<ll> > q;//小根堆 
	// cin >> n;
    rep(i,1,n){
        // cin>>a[i];
        q.push(a[i     ]);
    }
    //寄一次只能染出一种颜色,贪心染最贵的
    //12 + 7 + 4 + 2 
    ll ans=0;
    while (q.size()>1)
    {
        ll t=q.top();
        q.pop();
        t+=q.top();
        q.pop();
        cout<<t<<" ";
        ans+=t;
        q.push(t);
    }
    cout<<ans;
	return;
}
//25 + 20 + 15 +10 +5
int main()
{
#ifdef LOCAL
	freopen("/home/xiaobingdu/Downloads/in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		slove();
		slove2();
	}
	return 0;
}
//快读
inline int read() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x * f;
}
