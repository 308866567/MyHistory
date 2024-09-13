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
priority_queue<ll, vector<ll>, greater<ll>> q;

void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
        q.push(a[i]);
    }
    ll ans = 0;
    while (q.size() > 1)
    {
        ll t1 = q.top();
        q.pop();
        ll t2 = q.top();
        q.pop();
        ans += t1 + t2;
        q.push(t1+t2);
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