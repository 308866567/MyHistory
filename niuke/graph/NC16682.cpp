#include <iostream>
#include <unordered_map>
#include <deque>
#include <vector>
#define N 610
// #include <bits/stdc++.h>
using namespace std;
int n, p;    // n个节点,p条边
int ans = 999999; // 已经被隔离的人
int hmax;
class graph
{
public:
    // 不存在环
    unordered_map<int, unordered_map<int, bool>> G; // 1表示存在边
    vector<vector<int>> tree;                       // 每行代表一层,根节点在第1行
    int s[N] = {};                                  // 每个节点-该节点的子树总数
    int parent[N] = {};                             // 父节点
    bool used[N] = {};                              // n个节点,1表示被隔离
    int height[N] = {};
    void create(int i, int j)
    {
        G[i][j] = 1;
        parent[j] = i;
        return;
    }
    int dfs(int now) // 计算每个节点的子树个数
    {
        unordered_map<int, bool>::iterator it = G[now].begin();
        int sum = 0;
        for (; it != G[now].end(); it++)
        {
            sum += dfs(it->first);
        }
        if (G[now].empty())
        {
            s[now] = 0; // 叶子节点
            return 1;
        }
        s[now] = sum;
        return s[now] + 1;
    }
    int dfs2(int now, bool x) // 标记节点值为x
    {
        if (G[now].empty()) // 叶子节点
        {
            used[now] = x;
            return 1;
        }
        used[now] = x;
        // 访问子节点
        unordered_map<int, bool>::iterator it = G[now].begin();
        for (; it != G[now].end(); it++)
        {
            dfs2(it->first, x);
        }
        return 1;
    }
    int bfs(int x)
    {
        deque<int> q;
        q.push_back(x); // 头节点
        height[x] = 1;  // 头节点在第一层
        int c = 1;      // 记录当前所在层数
        while (!q.empty())
        {
            int size = q.size(); // 当前层的节点个数
            // 遍历当前层的节点, 添加下一层节点,已经减去的节点跳过
            for (int i = 0; i < size; i++) // 当前层有size个节点
            {
                int now = q.front();
                // 记录当前层上的节点
                height[now] = c;
                tree[c].push_back(now);
                // 添加下一层节点
                unordered_map<int, bool>::iterator it = G[now].begin();
                for (; it != G[now].end(); it++)
                {
                    q.push_back(it->first);
                }
                q.pop_front();
            }
            c++;
        }
        return c - 1;
    }
    void out() // 输出子树
    {
        for (int i = 0; i < n; i++)
        {
            s[i]++;
            // cout << s[i] << ' ';
        }
        // cout << '\n';
    }
    void out2()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << height[i] << ' ';
        }
        for (int i = 1; !tree[i].empty(); i++)
        {
            cout << i << "层: ";
            for (int j : tree[i]) // 选一个节点进入下一层
            {
                cout << j << " ";
            }
            cout << '\n';
        }
    }
    void BF(int j, int sum) // 当前在第j层进行决策.统计被隔离人数
    {
        // 更新答案
        ans = min(ans, n - sum);
        /*
    for (int i = 1; i <= n; i++)
    {
        if (used[i]) // 1表示被隔离的人
        {
            cout << i << ' '; // 被!感染(隔离)
        }
    }
    cout << "已经隔离人数:" << sum << '\n';
    //    */
        if (j > hmax)
        {
            return;
        }
        int size = tree[j].size(); // 空层为0
        // 访问当前层进行决策,穷举
        for (int i = 0; i < size; i++)
        {
            int now = tree[j][i]; // 当前的节点序号
            if (used[now])        // 当前节点已经被隔离
            {
                continue;
            }
            dfs2(now, 1);            // 标记其子树,表示被隔离
            BF(j + 1, sum + s[now]); // 隔离当前节点进入下一层
            dfs2(now, 0);            // 取消标记
        }
        // 当前层的节点全部被隔离或当前层没有节点返回
    }
};
int main()
{
    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> p;
    graph G;
    int ti, tj;
    int x;
    cin >> x >> tj;
    G.tree.resize(N); // 初始化,树高最多300
    G.create(x, tj);
    for (int i = 1; i < p; i++) // p条边
    {
        cin >> ti >> tj;
        G.create(ti, tj);
    }
    G.dfs(1);
    hmax = G.bfs(1);
    G.out();
    // G.out2();
    G.BF(2, 0); // 顶层不减去
    // 最少1人感染,即节点1被感染
    cout << ans; // 最少感染人数
    return 0;
}