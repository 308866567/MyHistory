#include <iostream>
#include <bits/stdc++.h>
#define N 305
using namespace std;
class graph
{
public:
    vector<vector<int>> tree;  // 树
    vector<vector<int>> depth; // 每层的节点,根节点在第0层
    vector<int> son;           // 每个节点的子节点个数
    int n, p;                  // 节点数,边数
    void in()                  // 输入
    {
        cin >> n >> p;
        tree.resize(N); // 初始化,树高最多300
        son.resize(N);
        int ti, tj;
        for (int i = 0; i < p; i++) // p条边
        {
            cin >> ti >> tj;
            create(ti, tj);
        }
    }
    void create(int i, int j) // 构建树
    {
        tree[i].push_back(j);
        return;
    }
    int dfs1(int now, int d) // 计算子节点树,每层有哪些节点
    {
        if (tree[now].empty()) // 叶子节点
        {
            depth[d].push_back(now);
            son[now] = 1;
            return 1;
        }
        int size = tree[now].size();
        int sum = 0;                   // 子节点个数
        for (int i = 0; i < size; i++) // 访问当前节点的子节点
        {
            sum += dfs1(tree[now][i], d + 1);
        }
        son[now] = sum + 1; // 加上自己本身
        return son[now];
    }
};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    graph G;
    G.in();
    G.dfs1(1, 0);
    return 0;
}