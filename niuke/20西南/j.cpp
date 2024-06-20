#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
typedef pair<double, double> pii;
ll n;
double cal(pii a, pii b)
{
    double dx = (a.first - b.first);
    double dy = (a.second - b.second);
    return sqrt(dx*dx+dy*dy);
}
pii a[5];
void solve()
{
    rep(i,1,4){
        cin>>a[i].first>>a[i].second;
    }
    int t[5]={1,2,3,4,1};
    double ans=0;
    rep(i,0,3){
        // cout<<cal(a[t[i]],a[t[i+1]])<<"\n";
        ans+=cal(a[t[i]],a[t[i+1]]);
    }
    printf("%.13lf",ans);
    
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
