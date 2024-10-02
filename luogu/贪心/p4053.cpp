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
struct node
{
    ll t1, t2;
    bool operator<(const node t) const
    {
        return t1 < t.t1;
    }
} a[N];
bool cmp(node x, node y)
{
    return x.t2 < y.t2;
}
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i].t1 >> a[i].t2;
    }
    sort(a + 1, a + 1 + n, cmp);
    priority_queue<node> q;
    ll ans = 0;
    ll sum = 0;
    // rep(i, 1, n)
    // {
    //     if (sum + a[i].t1 <= a[i].t2)
    //     {
    //         sum += a[i].t1;
    //         q.push(a[i]);
    //         ans++;
    //     }
    //     else
    //     {
    //         //优先添加a[i],添加后再弹出,避免当前a[i]所花时间过长
    //         q.push(a[i]);
    //         node t = q.top();
    //         sum = sum - t.t1 + a[i].t1;
    //         q.pop();
    //     }
    // }
    rep(i,1,n){
        sum+=a[i].t1;
        q.push(a[i]);
        if(sum<=a[i].t2){
            ans++;
        }else{
            sum-=q.top().t1;
            q.pop();
        }
    }
    /*
    
    */
    cout << ans << "\n";
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