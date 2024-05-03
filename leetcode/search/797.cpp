#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<bool> onpath;
    vector<bool> visited;
    vector<int> ans;
    vector<vector<int>> anss;
    int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) //有向无环图（DAG）
    {
        n = graph.size(); // n个节点,从0开始
        onpath.resize(n + 2);
        visited.resize(n + 2);
        dfs(0, graph);
        return anss;
    }
    void out()
    {
        anss.push_back(ans);
        // for (int i : ans)
        //     cout << i << " ";
        // cout << "\n";
    }
    void dfs(int now, vector<vector<int>> &graph)
    {
        // if (visited[now]) //有环
        // {
        //     out();
        //     return;
        // }
        visited[now] = 1;
        onpath[now] = 1;
        ans.push_back(now);
        if (now == n - 1) //起点到终点输出
        {
            out();
            ans.pop_back();
            return;
        }
        int size = graph[now].size();
        for (int i = 0; i < size; i++)
        {
            dfs(graph[now][i], graph);
        }
        onpath[now] = 0;
        ans.pop_back();
    }
};

int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    vector<vector<int>> graph = {{4,3,1}, {3,2,4}, {3}, {4},{}};
    Solution aa;
    aa.allPathsSourceTarget(graph);
    return 0;
}