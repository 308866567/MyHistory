#include <bits/stdc++.h>
using namespace std;
class UF
{
private:
    // 连通分量个数
    int count;
    //父节点数组
    int *parent;
    // int *size; // 新增一个数组记录树的“重量”
public:
    UF uf(int n) /* 构造函数，n 为图的节点总数 */
    {
        count = n;
        parent = new int[n]; // 存储每个节点的父节点
        // 最初每棵树只有一个节点
        // size = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // 父节点指针初始指向自己
            // size[i] = 1;   // 重量应该初始化 1
        }
    };

public:
    void un(int p, int q) //连通两个量
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        // 小树接到大树下面，较平衡
        // if (size[rootP] > size[rootQ])
        // {
        //     parent[rootQ] = rootP;
        //     size[rootP] += size[rootQ];
        // }
        // else
        // {
        //     parent[rootP] = rootQ;
        //     size[rootQ] += size[rootP];
        // }
        parent[rootP] = rootQ; // 将两棵树合并为一棵
        count--;               // 两个分量合二为一
    }

private:
    int find(int x) /* 作用:返回某个节点 x 的根节点 */
    {
        // 根节点的 parent[x] == x,每次循环往根靠近一个
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]]; //路径压缩，减小高度
            x = parent[x];
        }
        return x;
    }

public:
    int count()
    {
        return count; /* 返回当前的连通分量个数 */
    }
};
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;
        int n = board[0].size();  //列
        int m = board.size() / n; //行d
        UF uf;
        uf.uf(m * n + 1);
        int dummy = m * n;
        // 方向数组 d 是上下左右搜索的常用手法
        int d[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (int i = 1; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
                if (board[i][j] == 'O')//如果满足开始搜索// 将此 O 与上下左右的 O 连通
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (board[x][y] == 'O')
                            uf.un(x * n + y, i * n + j);
                    }
    }
};