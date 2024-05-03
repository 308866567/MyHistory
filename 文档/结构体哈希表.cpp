#include <iostream>
#include <deque>
#include <map>
#include <unordered_map>
using namespace std;
int S = 1, N = 1, M = 1;
struct room // 房间里当前3个容器的状态
{
    int v[4];
    room() {}
    room(int x, int y, int z)
    {
        v[1] = x;
        v[2] = y;
        v[3] = z;
    }
    bool operator==(const room &A) const
    {
        return (v[1] == A.v[1] && v[2] == A.v[2] && v[3] == A.v[3]);
    }
};
//使用[]需要先访问使其进行初始化,然后才可以进行其他操作
struct roomHash
{
    std::size_t operator()(const room &s) const // 自定义的哈希函数,注意哈希冲突
    {
        std::size_t h1 = hash<int>{}(s.v[1]);
        std::size_t h2 = hash<int>{}(s.v[2]);
        std::size_t h3 = hash<int>{}(s.v[3]);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};
class Room
{
public:
    unordered_map<room, int, roomHash> used; // 状态-最少步骤到达当前状态
    int half;                                // 最大液体的一半
    int ans = 9999999;
    int v[4] = {}; // 各个容器的max容积
    int a, b, c;
    Room(int S, int N, int M)
    {
        v[1] = S;
        v[2] = N;
        v[3] = M;
        half = v[1] / 2;
        bfs();
        if (ans == 9999999)
            cout << "NO\n";
        else
            cout << ans << "\n";
    }
    int bfs()
    {
        deque<room> q;
        q.push_back(room(v[1], 0, 0));
        used[room(v[1], 0, 0)] = 1;
        int size = 1;
        room f;
        int step = 1;
        while (!q.empty())
        {
            size = q.size();
            for (int i = 0; i < size; i++) // 遍历当前层
            {
                // 检查上一层是否出现过
                f = q.front();
                if ((f.v[1] == half && f.v[3] == half) || (f.v[2] == half && f.v[3] == half) || (f.v[1] == half && f.v[2] == half))
                {
                    if (step < ans)
                        ans = step -1;
                    return 1;
                }
                q.pop_front();
                add(f, q);
                // 添加下一步的状态,同时标记
            }
            step++;
            // cout << "\n";
        }
        return 1;
    }
    void add(room &now, deque<room> &q) // 6次情况尝试
    {
        room t;
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                if (i == j || now.v[i] < 1 || now.v[j] >= v[j])
                    continue; // i没有液体// j已经是满的
                t = now;
                move(t, i, j); // 修改t
                // 判断t是否重复
                // cout<<used[t]<<" ";
                // cout << t.v[1] << '-' << t.v[2] << '-' << t.v[3] << "  ";
                used[t];
                if (used[t] != 11) // 没出现过,记录,添加
                {
                    q.push_back(t);
                    used[t] = 11;
                    // cout << t.v[1] << '-' << t.v[2] << '-' << t.v[3] << "  ";
                }
            }
        }
        return;
    }
    int move(room &now, int &a, int &b) // 序号a的杯子倒给序号b的杯子
    {
        int sum = now.v[a] + now.v[b]; // 假设全倒给b
        if (sum <= v[b])               // b能装下
        {
            now.v[b] = sum;
            now.v[a] = 0;
            return 1;
        }
        else
        {
            now.v[b] = v[b];
            now.v[a] = sum - v[b];
            return 1;
        }
        return 0;
    }
};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    while (1)
    {
        cin >> S >> N >> M;
        if (0 == S + N + M)
            return 0;
        if (S % 2)
        {
            cout << "NO\n";
            continue;
        }
        // cout << ans;
        Room a(S, N, M);
    }
    return 0;
}