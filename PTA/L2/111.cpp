#include <iostream>
#include <deque>
using namespace std;
int dir[6][3] = {0, 0, -1, 0, 0, 1, 0, -1, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0}; // 左右上下
struct point
{
    int z;
    int x;
    int y;
    point() {}
    point(int &a, int &b, int &c)
    {
        z = a;
        x = b;
        y = c;
    }
};
long ans = 0;
long M, N, L, T;
bool arr[61][1287][129] = {}; // i张j行k列
long bfs(point a)
{
    long sum = 0;
    deque<point> q;
    q.push_back(a);
    point h;
    int z, x, y;
    while (!q.empty())
    {
        h = q.front();
        q.pop_back();
        for (int i = 0; i < 6; i++)
        {
            z = h.z + dir[i][0];
            x = h.x + dir[i][1];
            y = h.y + dir[i][2];
            // 越界
            if (z < 0 || z >= L || x < 0 || x >= M || y < 0 || y >= N)
                continue;
            if (arr[z][x][y])
            {
                arr[z][x][y] = 0;
                sum++;
                q.push_back(point(z, x, y));
            }
        }
    }
    if (sum >= T)
        ans += sum;
    return sum;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> L >> T;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (arr[i][j][k])
                    bfs(point(i, j, k));
            }
        }
    }
    cout << ans;
    return 0;
}