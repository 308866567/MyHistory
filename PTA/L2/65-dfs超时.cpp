// https://pintia.cn/problem-sets/1637422699704676352/exam/problems/1639130830825750528
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
// M�ǿ��ٵ�·��������S�ǳ����صĳ��б�ţ�D��Ŀ�ĵصĳ��б�š�
int n, m, s, d; // n���ڵ�,s���,d�յ�
int man[501];
vector<int> minpath;
int minn = 0x3f3f3f3f, l, ans;
class Graph
{
public:
    // ���,�յ�,Ȩֵ
    unordered_map<int, unordered_map<int, int>> g;
    // int g[501][501] = {0};
    bool used[501] = {0};            // ���500���ڵ�
    vector<int> path;                // �洢·��
    int dist[501];                   // ��㵽i����̾���
    void create(int a, int b, int c) // ��ӱ�
    {
        if (g[a][b] == 0)
            g[a][b] = 0x3f3f3f3f;
        g[a][b] = min(g[a][b], c);
        if (g[b][a] == 0)
            g[b][a] = 0x3f3f3f3f;
        g[b][a] = min(g[a][b], c);
    }
    int dfs(int now, int len, int sum) // lenΪ·������,sumΪ��Ԯ��������
    {
        if (used[now])
            return -1;
        if (now == d) // �����յ�
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
            // ���´�
            if (len <= minn)
            {
                if (len == minn)
                {
                    l++;
                    if (sum > ans) // ���¾�Ԯ���������
                    {
                        ans = sum;
                        minpath = path;
                    }
                }
                else // �µ����·
                {
                    minn = len; // �������·���ĳ���
                    ans = sum;
                    minpath = path;
                    l = 1;
                }
            }
            return 1;
        }
        used[now] = 1;       // ��ֹ��
        path.push_back(now); // ��¼·��
        unordered_map<int, int>::iterator it;
        for (it = g[now].begin(); it != g[now].end(); it++) // ������
        {
            dfs(it->first, len + it->second, sum + man[it->first]);
        }
        path.pop_back();
        used[now] = 0; // ��ֹ��
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