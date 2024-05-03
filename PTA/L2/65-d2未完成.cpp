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
// ��
vector<int> minpath;
int ans1 = 1, ans2 = 0;
const int N = 501;
int man[N];
int rode[N] = {};
typedef pair<int, int> PII;
struct cmp // ���бȽ�
{
    bool operator()(const PII &a, const PII &b)
    {
        return a.second > b.second;
    }
};

bool cmp1(vector<int> &a, vector<int> &b) // ����ȷ���1
{
    int size = min(a.size(), b.size());
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
            return 1;
    }
    return 0;
}
class Graph
{
public:
    // ���,�յ�,Ȩֵ
    unordered_map<int, unordered_map<int, int>> g;
    void create(int a, int b, int c) // ��ӱ�
    {
        if (g[a][b] == 0)
            g[a][b] = 0x3f3f3f3f;
        g[a][b] = min(g[a][b], c);
        if (g[b][a] == 0)
            g[b][a] = 0x3f3f3f3f;
        g[b][a] = min(g[a][b], c);
    }
    int dijkstra2(int start) // Ѱ�ҵ�Դ���·
    {
        int dist[N] = {};                     // ��¼s����������·������
        int parent[N] = {};                   // ��¼·��
        memset(dist, 0x3f3f3f, sizeof(dist)); // ��ʼ��
        dist[start] = 0;                      // ���
        parent[start] = -1;                   // ���ĸ��ڵ㲻����
        rode[start] = 1;
        priority_queue<PII, vector<PII>, cmp> q; // ���ȶ��б�֤ͷ�ڵ�һ����������������ת�ڵ�
        q.push(PII(start, 0));

        while (!q.empty())
        {
            int t = q.top().first;  // ��ת�ڵ�
            int w = q.top().second; // ����ת�ڵ�ľ���
            // cout << t << ' ';
            q.pop();
            if (w > dist[t]) // �Ѿ���һ�����̵�·��������ת�ڵ��򷵻�
                continue;
            for (auto it = g[t].begin(); it != g[t].end(); it++)
            {
                int next = it->first;
                int l = it->second + w;
                // �������·
                if (l <= dist[next])
                {
                    if (l == dist[next])
                    {
                        rode[next] += rode[t];
                    }
                    else
                        rode[next] = rode[t];
                    dist[next] = l;
                    q.push(PII(next, l));
                    parent[next] = t;
                    if (next == d)
                    {
                        if (l == dist[next]) // ����ͬ��������·,�ж�sum˭����
                        {
                            vector<int> ss = path2(parent, d);
                            if (cmp1(ss, minpath) && ans1 != 0)
                                ans1++; // �ظ�·��?
                            int tt = path(parent, d, 0);
                            if (tt > ans2)
                            {
                                minpath.clear();
                                path(parent, d, 1);
                                ans2 = tt;
                            }
                        }
                        else // �и�С��·��,����ans2��minpath
                        {
                            ans1 = 1;
                            minpath.clear();
                            ans2 = path(parent, d, 1);
                        }
                    }
                }
            }
        }
        // cout << "\nans";
        // path(parent, d, 0);
        outans();
        return 0;
    }
    void outans()
    {
        cout << rode[d] << ' ' << ans2 << "\n";
        for (int i = 0; i < minpath.size(); i++)
        {
            cout << minpath[i];
            if (i < minpath.size() - 1)
                cout << ' ';
        }
    }
    void out(int *a, int l)
    {
        for (int i = 0; i < l; i++)
        {
            cout << a[i] << ' ';
        }
        cout << "\n";
    }
    vector<int> path2(int *parent, int end) // ����·������
    {
        int sum = 0;
        vector<int> t;
        int x = end;
        while (x != -1)
        {
            t.push_back(x);
            // cout << x << " ";
            x = parent[x];
        }
        return t;
    }
    int path(int *parent, int end, bool f) // ���·��,1��ʾ���´�
    {
        // cout << ans << "\n";
        int sum = 0;
        vector<int> t;
        int x = end;
        while (x != -1)
        {
            t.push_back(x);
            // cout << x << " ";
            x = parent[x];
        }
        // cout << "\n";
        for (int i = t.size() - 1; i >= 0; i--) // �������
        {
            // cout << t[i] << " ";
            if (f)
                minpath.push_back(t[i]);
            sum += man[t[i]];
        }
        return sum;
    }
};
int main()
{
    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
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
    G.dijkstra2(0);
    return 0;
}