#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
#define ls u << 1
#define rs u << 1 | 1
typedef pair<ll, ll> pii;
const ll N = 1e6;
ll n, m, a[N];
struct Tree
{ // 线段树
    ll l, r;
    // 区间和,最大左子段和,最大右子段和,最大子段和
    ll sum, lmx, rmx, mx;
} tr[N * 4];

inline void pushup(Tree &u, Tree l, Tree r)
{
    u.sum = l.sum + r.sum;
    u.lmx = max(l.lmx, l.sum + r.lmx);
    u.rmx = max(r.rmx, r.sum + l.rmx);
    u.mx = max(max(l.mx, r.mx), l.rmx + r.lmx);
}
inline void build(ll u, ll l, ll r)
{ // 建树
    tr[u] = {l, r, a[r], a[r], a[r], a[r]};
    if (l == r)
        return;
    ll m = l + r >> 1;
    build(ls, l, m);
    build(rs, m + 1, r);
    pushup(tr[u], tr[ls], tr[rs]);
}
inline void change(ll u, ll x, ll v)
{ // 点修
    if (tr[u].l == tr[u].r)
    {
        tr[u] = {x, x, v, v, v, v};
        return;
    }
    ll m = tr[u].l + tr[u].r >> 1;
    if (x <= m)
        change(ls, x, v);
    else
        change(rs, x, v);
    pushup(tr[u], tr[ls], tr[rs]);
}
inline Tree query(ll u, ll x, ll y)
{ // 区查
    if (x <= tr[u].l && tr[u].r <= y)
        return tr[u];
    ll m = tr[u].l + tr[u].r >> 1;
    if (y <= m)
        return query(ls, x, y);
    if (x > m)
        return query(rs, x, y);
    Tree T; // 开一个临时节点，存储拼凑结果
    pushup(T, query(ls, x, m), query(rs, m + 1, y));
    return T;
}
vector<ll> ans;
vector<pii> qq;
int  main()
{
#ifdef LOCAL
    freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
    freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        qq.push_back(pii(x, y));
        ans.push_back(query(1, x, y).mx);
    }
    memset(tr,0,sizeof tr);
    for (ll i = 1; i <= n; i++)
        a[i] = -a[i];
    build(1, 1, n);
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        x = qq[i].first, y = qq[i].second;
        ans[i] = max(ans[i], query(1, x, y).mx);
    }
    for (ll i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}