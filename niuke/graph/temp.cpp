#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 310, M = 610;
int n, m;
int h[N], e[M], ne[M], c[M], idx;
int Size[N];
vector<int> level[N];
int ans = N, max_depth;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs_level(int u, int depth, int father)
{
    Size[u] = 1;
    max_depth = max(max_depth, depth);
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            level[depth].push_back(i);
            Size[u] += dfs_level(j, depth + 1, u);
        }
    }
    return Size[u];
}
void dfs_draw(int i, bool color)
{
    c[i] = color;
    for (int j = h[e[i]]; j != -1; j = ne[j])
        if (j != (i ^ 1))
            dfs_draw(j, color);
}
void dfs(int u, int s)
{
    ans = min(ans, n - s);
    if (u == max_depth)
        return;
    for (auto i : level[u])
        if (!c[i])
        {
            dfs_draw(i, true);
            dfs(u + 1, s + Size[e[i]]);
            dfs_draw(i, false);
        }
}

int main()
{
    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs_level(1, 0, -1);//预处理出每一层的节点集合，以及每棵子树的大小。 
    dfs(0, 0);
    cout << ans << endl;
     for (int i =0;i<n;i++)
    {
        cout<<Size[i]<<' ';
    }
    cout<<'\n';
       for (int i =0;i<n;i++)
    {
        cout<<e[i]<<' ';
    }
    return 0;
}