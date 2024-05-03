#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
class G
{
public:
    int n, m;                  // �ڵ���,����
    int k;                     // k��ѯ��
    vector<vector<int>> graph; // u��v����̾���
    vector<vector<int>> path;  // u��v����ת�ڵ�
    void in()                  // ����
    {
        cin >> n >> m >> k;
        int u, v, w;
        graph.resize(n + 1);
        path.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            path[i].resize(n + 1, -1);   // �ڵ���Ŵ�1��ʼ
            graph[i].resize(n + 1, INF); // ������Ȩֵ��ʾû��ֱ�ӵı�
            graph[i][i] = 0;
        }
        for (int i = 0; i < m; i++) // p����
        {
            cin >> u >> v >> w;
            graph[u][v] = min(w,graph[u][v]);
        }
        floyd();
        slove();
    }
    void slove() // ����ѯ��
    {
        int x, y;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            if (graph[x][y] > INF / 2)
                cout << "impossible\n";
            else
                cout << graph[x][y] << "\n";
        }
    }
    void floyd()
    {
        for (int mid = 1; mid <= n; mid++) // ���ÿ����ת�ڵ�
            for (int u = 1; u <= n; u++)
                for (int v = 1; v <= n; v++)
                // if (u != v && mid != u && mid != v) // ������ת�ڵ����������
                {
                    graph[u][v] = min(graph[u][mid] + graph[mid][v], graph[u][v]);
                    path[u][v] = mid;
                }
    }
};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    G g;
    g.in();
    return 0;
}