#include <iostream>
using namespace std;
struct s
{
    long long a;
    int b;
    int c;
} st[1002];
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n, m;
    cin >> n;
    long long a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        st[b].a = a;
        st[b].b = b;
        st[b].c = c;
    }
    cin>>m;
    int temp; // ²éÑ¯ÊÔ»ú×ùÎ»ºÅ
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        cout << st[temp].a << ' ' << st[temp].c << '\n';
    }
    return 0;
}