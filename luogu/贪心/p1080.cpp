#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
class gao
{
    public:
    ll lm, la, lt;
    // 倒序存数
    ll m[N], a[N], t[N];
    // m[]乘b
    void mul(ll m[], ll b, ll t[])
    {
        rep(i, 1, lt) t[i] = 0;
        rep(i, 1, lm) t[i] += m[i] * b;
        lm += 4; // 乘法进位,具体看最多能进几位
        rep(i, 1, lm-1)
        {
            t[i + 1] += t[i] / 10;
            t[i] %= 10;
        }
        //去前导0
        while (t[lm] == 0 && lm > 1)
            lm--;
        rep(i, 1, lm) m[i] = t[i];
    }
    // 除
    void div(ll m[], int b, ll t[])
    {
        rep(i, 1, lt) t[i] = 0;
        ll r = 0;//余数
        //高位向低位
        rrep(i, lm, 1)
        {
            r = r * 10 + m[i];//被除数
            t[i] = r / b;//商
            r %= b;//余数
        }
        lt = lm;
        //去前导0
        while (t[lt] == 0 && lt > 1)
            lt--;
    }
    // 高精度比较
    bool cmp(ll a[], ll t[])
    {
        if (la != lt)
            return la < lt;
        for (ll i = lt; i; i--)
        {
            if (a[i] != t[i])
            {
                return a[i] < t[i];
            }
        }
        return false; // 相等时
    }
    void upd(ll a[], ll t[])
    {
        if (cmp(a, t))
        {
            // 更新答案
            for (int i = lt; i; i--)
            {
                a[i] = t[i];
            }
            la = lt;
        }
    }
}g;
ll n;
struct node
{
    ll a, b;
    bool operator<(const node t)
    {
        return a * b < t.a * t.b;
    }
} arr[N];
// 高精度
void solve()
{
    cin >> n;
    cin >> arr[0].a >> arr[0].b; // 国王
    rep(i, 1, n)
    {
        cin >> arr[i].a >> arr[i].b;
    }
    sort(arr + 1, arr + 1 + n);
    // ll ans = -1;
    // ll l = arr[0].a;
    g.m[++g.lm]=arr[0].a;
    rep(i, 1, n)
    {
        g.div(g.m,arr[i].b,g.t);
        g.upd(g.a,g.t);
        g.mul(g.m,arr[i].a,g.t);
        // ans = max(ans, l / arr[i].b);
        // l *= arr[i].a;
    }
    rrep(i,g.la,1){
        cout<<g.a[i];
    }
    // cout << ans << "\n";
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