#include <iostream>
#include <bits/stdc++.h>
#define N 305
using namespace std;
class graph
{
public:
    vector<vector<int>> tree;  // ��
    vector<vector<int>> depth; // ÿ��Ľڵ�,���ڵ��ڵ�0��
    vector<int> son;           // ÿ���ڵ���ӽڵ����
    int n, p;                  // �ڵ���,����
    void in()                  // ����
    {
        cin >> n >> p;
        tree.resize(N); // ��ʼ��,�������300
        son.resize(N);
        int ti, tj;
        for (int i = 0; i < p; i++) // p����
        {
            cin >> ti >> tj;
            create(ti, tj);
        }
    }
    void create(int i, int j) // ������
    {
        tree[i].push_back(j);
        return;
    }
    int dfs1(int now, int d) // �����ӽڵ���,ÿ������Щ�ڵ�
    {
        if (tree[now].empty()) // Ҷ�ӽڵ�
        {
            depth[d].push_back(now);
            son[now] = 1;
            return 1;
        }
        int size = tree[now].size();
        int sum = 0;                   // �ӽڵ����
        for (int i = 0; i < size; i++) // ���ʵ�ǰ�ڵ���ӽڵ�
        {
            sum += dfs1(tree[now][i], d + 1);
        }
        son[now] = sum + 1; // �����Լ�����
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