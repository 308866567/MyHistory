#include <iostream>
using namespace std;
long long n, m, q;
long long ans = 0;
bool hang[100005], lie[100005];
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> m >> q;
    ans = n * m;
    long long a, b;
    long long t = 0, p = 0; // ��ʾ��t�б����
    for (long long i = 1; i <= q; i++)
    {
        cin >> a >> b;
        if (a == 1) // 1Ϊ��
        {
            if (lie[b] == 0)
            {
                p++;
            }
            lie[b] = 1;
        }
        else // 0Ϊ��
        {
            if (hang[b] == 0)
            {
                t++;
            }
            hang[b] = 1;
        }
    }
    cout << ans + p * t - p * m - t * n;
    return 0;
}