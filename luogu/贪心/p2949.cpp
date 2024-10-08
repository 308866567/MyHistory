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
    ll d, p;
    bool operator<(const node t) const
    {
        if (d == t.d)
            return p > t.p;
        return d < t.d;
    }
} a[N];
priority_queue<ll,vector<ll>,greater<ll>> q; // 小根堆
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i].d >> a[i].p;
    }
    ll ans = 0;
    sort(a + 1, a + 1 + n);
    rep(i, 1, n)
    {
        // if (a[i].d == q.size())
        // {
        //     if (a[i].p > q.top())
        //     {
        //         ans -= q.top();
        //         q.pop();
        //         q.push(a[i].p);
        //         ans += a[i].p;
        //     }
        // }
        // else
        // {
        //     q.push(a[i].p);
        //     ans += a[i].p;
        // }
        if (q.size() < a[i].d)
        {
            q.push(a[i].p);
            ans += a[i].p;
        }
        else if (q.size() == a[i].d && a[i].p > q.top())
        {
            ans -= q.top();
            q.pop();
            q.push(a[i].p);
            ans += a[i].p;
        }
    }
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