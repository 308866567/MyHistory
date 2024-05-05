#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n, m, k;
ll arr[555][555];
ll s[555][555];
struct Node
{
    ll i, j; // 矩阵左上角
    ll you, xia;
    ll val;
    bool f; // 1表示上一次是加右，这次不能加下
    void up()
    {
        val = s[i - 1][j - 1] + s[i + xia - 1][j + you - 1] - s[i + xia - 1][j - 1] - s[i - 1][j + you - 1];
    }
};
queue<Node> q;
void slove()
{
    cin >> n >> m >> k;
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            cin >> arr[i][j];
            q.push({i, j, 1, 1, arr[i][j], 0});
            s[i][j] = arr[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; // 处理出二维前缀和
        }
    }
    ll ans = 0;
    rep(i1, 1, n)
    { // 子矩阵上边界
        rep(i2, i1, n)
        { // 子矩阵下边界
            // 如果搜索到的一个矩阵满足题目要求（其内部元素之和<=k）那么它的子矩阵都满足要求
            // 双指针移动左右边界

            for (ll l = 1, r = 1; l <= m; l++)
            {
                // ll sum = s[i2][r] + s[i1 - 1][l - 1] - s[i2][l - 1] - s[i1 - 1][r];
                //寻找一个最大的右边界,不需要每次l更新都从l起找最大的右边界
                while (r<=m&&s[i2][r] + s[i1 - 1][l - 1] - s[i2][l - 1] - s[i1 - 1][r]<= k)
                {
                    r++;
                }
                ans += r - l ; // 快速统计横向的l到r
            }
        }
    }
    cout << ans;
    return;
}
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
    }
    return 0;
}
// 快读
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}