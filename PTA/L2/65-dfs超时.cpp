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
int man[501];
vector<int> minpath;
int minn = 0x3f3f3f3f, l, ans;
class Graph
{
public:
    // 起点,终点,权值
    unordered_map<int, unordered_map<int, int>> g;
    // int g[501][501] = {0};
    bool used[501] = {0};            // 最多500个节点
    vector<int> path;                // 存储路径
    int dist[501];                   // 起点到i的最短距离
    void create(int a, int b, int c) // 添加边
    {
        if (g[a][b] == 0)
            g[a][b] = 0x3f3f3f3f;
        g[a][b] = min(g[a][b], c);
        if (g[b][a] == 0)
            g[b][a] = 0x3f3f3f3f;
        g[b][a] = min(g[a][b], c);
    }
    int dfs(int now, int len, int sum) // len为路径长度,sum为救援队人数和
    {
        if (used[now])
            return -1;
        if (now == d) // 到达终点
        {
            // sum+=man[d];
            /*
            for (int i : path)
            {
                cout << i << ' ';
            }
            cout << d << " -";
            cout << len << ' ' << sum;
            cout << '\n';
            //*/
            // 更新答案
            if (len <= minn)
            {
                if (len == minn)
                {
                    l++;
                    if (sum > ans) // 更新救援队最大人数
                    {
                        ans = sum;
                        minpath = path;
                    }
                }
                else // 新的最短路
                {
                    minn = len; // 更新最短路径的长度
                    ans = sum;
                    minpath = path;
                    l = 1;
                }
            }
            return 1;
        }
        used[now] = 1;       // 防止环
        path.push_back(now); // 记录路径
        unordered_map<int, int>::iterator it;
        for (it = g[now].begin(); it != g[now].end(); it++) // 遍历边
        {
            dfs(it->first, len + it->second, sum + man[it->first]);
        }
        path.pop_back();
        used[now] = 0; // 防止环
        return 0;
    }
};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
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
    G.dfs(0, 0, man[s]);
    cout << l << ' ' << ans;
    cout << '\n';
    for (int i : minpath)
    {
        cout << i << ' ';
    }
    cout << d << "";
    return 0;
}