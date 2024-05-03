#include <bits/stdc++.h>
using namespace std;
class UF
{
private:
    int count;   // 连通分量个数
    int *parent; // 父节点数组
public:
    UF(int n) /* 构造函数，n 为图的节点总数 */
    {
        count = n;
        parent = new int[n]; // 存储每个节点的父节点
        // 最初每棵树只有一个节点
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // 父节点指针初始指向自己
        }
    };

public:
    void un(int p, int q) // 连通两个量
    {
        int rootP = find(p); // p的根节点下标
        int rootQ = find(q); // q的根节点下标
        if (rootP == rootQ)
            return;
        parent[rootP] = rootQ; // 将两棵树合并为一棵
        count--;               // 两个分量合二为一
    }

private:
    int find(int x) /* 作用:返回某个节点 x 的根节点 */
    {
        // 根节点的 parent[x] == x,每次循环往根靠近一个
        while (parent[x] != x) // 根节点的父节点为自己本身
        {
            // 每次 while 循环都会把一对儿父子节点改到同一层
            // 一次只减少一层,
            // x节点的父亲更新为爷爷
            parent[x] = parent[parent[x]]; // 路径压缩，减小高度
            x = parent[x];
        }
        return x;
    }
    // int find(int x)//更快的路径压缩写法,
    // {   //递归写法会把路上的所有节点移到根节点下
    //     //把 x 到根节点之间的所有节点直接接到根节点下面
    //     if (parent[x] != x)//没到达根节点,继续往根节点开递归
    //     {
    //    //所有节点都直接移动到根节点下
    //         parent[x] = find(parent[x]);
    //     }
    //     return parent[x];//最后一层递归返回根节点
    // }

public:
    int count()
    {
        return count; /* 返回当前的连通分量个数 */
    }
};