// https://pintia.cn/problem-sets/1637422699704676352/exam/problems/1639130830825750528
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <queue>
// 19 : 53
using namespace std;
const int N = 501, inf = 0x3f3f3f3f;
class slove
{
public:
    // M�ǿ��ٵ�·��������S�ǳ����صĳ��б�ţ�D��Ŀ�ĵصĳ��б�š�
    int n, m, S, D; // n���ڵ�,s���,d�յ�
    int g[N][N];
    int man[N];  // ÿ���ڵ�ľ�Ԯ������
    int dist[N]; // ��㵽�����ڵ�����·
    int rode[N]; // �����ڵ�����·����
    int w[N];//�����ڵ����·�ϵ�����Ԯ������
    int parent[N]; // ���ڵ�
    bool visit[N];//����
    vector<int> anspath;
    slove()
    {
        memset(g, inf, sizeof(g));
        memset(dist, inf, sizeof(dist));
        memset(visit, 0, sizeof(visit));
        memset(rode, 0, sizeof(rode));
        memset(w, 0, sizeof(w));
        in();
        dijkstra1(S);
        cout << rode[D] << ' ' << w[D] << "\n";//��һ��
        findpath(); // ����·��
        outpath();//�ڶ���
    }
    void in()
    {
        cin >> n >> m >> S >> D;
        for (int i = 0; i < n; i++)
        {
            cin >> man[i];
        }
        int a, b, c;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            g[a][b] = min(g[a][b], c);
            g[b][a] = min(g[b][a], c);
        }
    }
    void dijkstra1(int start)
    {
        dist[start] = 0;
        rode[start] = 1;
        w[start] = man[start];
        for (int i = 0; i < n - 1; i++)
        {
            int t = -1;
            for (int j = 0; j < n; j++) // Ѱ����ת
            {
                if (!visit[j] && (t == -1 || dist[j] < dist[t]))
                    t = j;
            }
            visit[t] = 1;
            for (int j = 0; j < n; j++) // �������·
            {
                if (dist[t] + g[t][j] < dist[j]) // ���¾���
                {
                    dist[j] = dist[t] + g[t][j];
                    rode[j] = rode[t];
                    parent[j] = t;
                    w[j] = w[t] + man[j];
                }
                else if (dist[t] + g[t][j] == dist[j]) // ����һ�����벻����µ����·�߷�
                {
                    rode[j] += rode[t];
                    if (w[j] < w[t] + man[j])
                    {
                        w[j] = w[t] + man[j];
                        parent[j] = t;
                    }
                }
            }
        }
        return;
    }
    void findpath() // ����·��
    {
        anspath.clear();
        int t = D;
        parent[S] = -1;
        while (t != -1) //
        {
            anspath.push_back(t);
            t = parent[t];
        }
    }
    void outpath()
    {
        for (int i = anspath.size() - 1; i > -1; i--)
        {
            cout << anspath[i];
            if (i > 0)
                cout << ' ';
        }
    }
};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    slove a;
    return 0;
}