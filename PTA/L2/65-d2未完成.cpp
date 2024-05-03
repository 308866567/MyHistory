// https://pintia.cn/problem-sets/1637422699704676352/exam/problems/1639130830825750528
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
// M是快速道路的条数；S是出发地的城市编号；D是目的地的城市编号。
int n, m, s, d; // n个节点,s起点,d终点
// 答案
vector<int> minpath;
int ans1 = 1, ans2 = 0;
const int N = 501;
int man[N];
int rode[N] = {};
typedef pair<int, int> PII;
struct cmp // 队列比较
{
    bool operator()(const PII &a, const PII &b)
    {
        return a.second > b.second;
    }
};

bool cmp1(vector<int> &a, vector<int> &b) // 不相等返回1
{
    int size = min(a.size(), b.size());
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
            return 1;
    }
    return 0;
}
class Graph
{
public:
    // 起点,终点,权值
    unordered_map<int, unordered_map<int, int>> g;
    void create(int a, int b, int c) // 添加边
    {
        if (g[a][b] == 0)
            g[a][b] = 0x3f3f3f3f;
        g[a][b] = min(g[a][b], c);
        if (g[b][a] == 0)
            g[b][a] = 0x3f3f3f3f;
        g[b][a] = min(g[a][b], c);
    }
    int dijkstra2(int start) // 寻找单源最短路
    {
        int dist[N] = {};                     // 记录s到各点的最短路径距离
        int parent[N] = {};                   // 记录路径
        memset(dist, 0x3f3f3f, sizeof(dist)); // 初始化
        dist[start] = 0;                      // 起点
        parent[start] = -1;                   // 起点的父节点不存在
        rode[start] = 1;
        priority_queue<PII, vector<PII>, cmp> q; // 优先队列保证头节点一定是离起点最近的中转节点
        q.push(PII(start, 0));

        while (!q.empty())
        {
            int t = q.top().first;  // 中转节点
            int w = q.top().second; // 到中转节点的距离
            // cout << t << ' ';
            q.pop();
            if (w > dist[t]) // 已经有一条更短的路径到达中转节点则返回
                continue;
            for (auto it = g[t].begin(); it != g[t].end(); it++)
            {
                int next = it->first;
                int l = it->second + w;
                // 更新最短路
                if (l <= dist[next])
                {
                    if (l == dist[next])
                    {
                        rode[next] += rode[t];
                    }
                    else
                        rode[next] = rode[t];
                    dist[next] = l;
                    q.push(PII(next, l));
                    parent[next] = t;
                    if (next == d)
                    {
                        if (l == dist[next]) // 是相同距离的最短路,判断sum谁更大
                        {
                            vector<int> ss = path2(parent, d);
                            if (cmp1(ss, minpath) && ans1 != 0)
                                ans1++; // 重复路径?
                            int tt = path(parent, d, 0);
                            if (tt > ans2)
                            {
                                minpath.clear();
                                path(parent, d, 1);
                                ans2 = tt;
                            }
                        }
                        else // 有更小的路径,更新ans2和minpath
                        {
                            ans1 = 1;
                            minpath.clear();
                            ans2 = path(parent, d, 1);
                        }
                    }
                }
            }
        }
        // cout << "\nans";
        // path(parent, d, 0);
        outans();
        return 0;
    }
    void outans()
    {
        cout << rode[d] << ' ' << ans2 << "\n";
        for (int i = 0; i < minpath.size(); i++)
        {
            cout << minpath[i];
            if (i < minpath.size() - 1)
                cout << ' ';
        }
    }
    void out(int *a, int l)
    {
        for (int i = 0; i < l; i++)
        {
            cout << a[i] << ' ';
        }
        cout << "\n";
    }
    vector<int> path2(int *parent, int end) // 返回路径数组
    {
        int sum = 0;
        vector<int> t;
        int x = end;
        while (x != -1)
        {
            t.push_back(x);
            // cout << x << " ";
            x = parent[x];
        }
        return t;
    }
    int path(int *parent, int end, bool f) // 输出路径,1表示更新答案
    {
        // cout << ans << "\n";
        int sum = 0;
        vector<int> t;
        int x = end;
        while (x != -1)
        {
            t.push_back(x);
            // cout << x << " ";
            x = parent[x];
        }
        // cout << "\n";
        for (int i = t.size() - 1; i >= 0; i--) // 倒序输出
        {
            // cout << t[i] << " ";
            if (f)
                minpath.push_back(t[i]);
            sum += man[t[i]];
        }
        return sum;
    }
};
int main()
{
    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> man[i];
    }
    Graph G;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.create(a, b, c);
    }
    G.dijkstra2(0);
    return 0;
}