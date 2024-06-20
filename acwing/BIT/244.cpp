#include <iostream>
#include <cstring>
typedef long long ll;
const ll N = 1e5 + 3;
using namespace std;
ll n;
ll a[N] = {0}, b[N] = {0};
int t[N] = {0}; // used数组,查询前缀和
inline ll lowbit(ll x)
{
    return x & (-x);
}
// 单点查询1-x的前缀和
inline ll query(ll x)
{
    ll sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += t[i];
    }
    return sum;
}
// 单点修改
inline void update(ll x, ll k)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        t[i] += k;
    }
}
int main()
{
    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
    }
    // 初始化
    for (int i = 1; i <= n; i++)
    {
        update(i, 1);
    }
    for (int i = n; i; i--)
    {
        int l = 1, r = n + 1, mid;
        while (l < r)
        {
            mid = l + r >> 1;
            // 左侧
            if (query(mid) >= a[i]+1)
                r = mid;
            else
                l = mid + 1;
        }
        b[i] = l;
        update(l, -1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << '\n';
    }
    return 0;
}
