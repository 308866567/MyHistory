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
ll h[N];
void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        cin >> h[i];
    }
    ll ans = h[1];
    ll now = h[1];
    rep(i, 2, n)
    {
        /*
        如果后面的大于当前目标，显然要多搞几次才行
        如果小于，现在在搞这一块的时候顺便就可以把下一块弄好了
        所以只要加上下一块比现在多的就可以了
        */
        if (h[i] > now)
        {
            ans += h[i] - now, now = h[i];
        }
        else
        {
            now = h[i];
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