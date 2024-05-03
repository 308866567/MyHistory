#include <iostream>
#include <unordered_map>
#include <deque>
#include <vector>
#define N 610
// #include <bits/stdc++.h>
using namespace std;
int n, p;    // n���ڵ�,p����
int ans = 999999; // �Ѿ����������
int hmax;
class graph
{
public:
    // �����ڻ�
    unordered_map<int, unordered_map<int, bool>> G; // 1��ʾ���ڱ�
    vector<vector<int>> tree;                       // ÿ�д���һ��,���ڵ��ڵ�1��
    int s[N] = {};                                  // ÿ���ڵ�-�ýڵ����������
    int parent[N] = {};                             // ���ڵ�
    bool used[N] = {};                              // n���ڵ�,1��ʾ������
    int height[N] = {};
    void create(int i, int j)
    {
        G[i][j] = 1;
        parent[j] = i;
        return;
    }
    int dfs(int now) // ����ÿ���ڵ����������
    {
        unordered_map<int, bool>::iterator it = G[now].begin();
        int sum = 0;
        for (; it != G[now].end(); it++)
        {
            sum += dfs(it->first);
        }
        if (G[now].empty())
        {
            s[now] = 0; // Ҷ�ӽڵ�
            return 1;
        }
        s[now] = sum;
        return s[now] + 1;
    }
    int dfs2(int now, bool x) // ��ǽڵ�ֵΪx
    {
        if (G[now].empty()) // Ҷ�ӽڵ�
        {
            used[now] = x;
            return 1;
        }
        used[now] = x;
        // �����ӽڵ�
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
        q.push_back(x); // ͷ�ڵ�
        height[x] = 1;  // ͷ�ڵ��ڵ�һ��
        int c = 1;      // ��¼��ǰ���ڲ���
        while (!q.empty())
        {
            int size = q.size(); // ��ǰ��Ľڵ����
            // ������ǰ��Ľڵ�, �����һ��ڵ�,�Ѿ���ȥ�Ľڵ�����
            for (int i = 0; i < size; i++) // ��ǰ����size���ڵ�
            {
                int now = q.front();
                // ��¼��ǰ���ϵĽڵ�
                height[now] = c;
                tree[c].push_back(now);
                // �����һ��ڵ�
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
    void out() // �������
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
            cout << i << "��: ";
            for (int j : tree[i]) // ѡһ���ڵ������һ��
            {
                cout << j << " ";
            }
            cout << '\n';
        }
    }
    void BF(int j, int sum) // ��ǰ�ڵ�j����о���.ͳ�Ʊ���������
    {
        // ���´�
        ans = min(ans, n - sum);
        /*
    for (int i = 1; i <= n; i++)
    {
        if (used[i]) // 1��ʾ���������
        {
            cout << i << ' '; // ��!��Ⱦ(����)
        }
    }
    cout << "�Ѿ���������:" << sum << '\n';
    //    */
        if (j > hmax)
        {
            return;
        }
        int size = tree[j].size(); // �ղ�Ϊ0
        // ���ʵ�ǰ����о���,���
        for (int i = 0; i < size; i++)
        {
            int now = tree[j][i]; // ��ǰ�Ľڵ����
            if (used[now])        // ��ǰ�ڵ��Ѿ�������
            {
                continue;
            }
            dfs2(now, 1);            // ���������,��ʾ������
            BF(j + 1, sum + s[now]); // ���뵱ǰ�ڵ������һ��
            dfs2(now, 0);            // ȡ�����
        }
        // ��ǰ��Ľڵ�ȫ���������ǰ��û�нڵ㷵��
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
    G.tree.resize(N); // ��ʼ��,�������300
    G.create(x, tj);
    for (int i = 1; i < p; i++) // p����
    {
        cin >> ti >> tj;
        G.create(ti, tj);
    }
    G.dfs(1);
    hmax = G.bfs(1);
    G.out();
    // G.out2();
    G.BF(2, 0); // ���㲻��ȥ
    // ����1�˸�Ⱦ,���ڵ�1����Ⱦ
    cout << ans; // ���ٸ�Ⱦ����
    return 0;
}