#include <iostream>
using namespace std;
long long s[2];
long long e[2];
long long slove()
{
    // yֻ��+1
    if (s[1] > e[1])
        return -99;
    long long y = e[1] - s[1]; // ��Ϊ��,��Ϊ��
    if (s[0] + y < e[0])       // x�������Ϊy
        return -99;
    s[0] += y;
    long long x = s[0] - e[0]; // ��Ϊ��,��Ϊ��
    // cout << x << ' ' << y << ' ';
    x = x > 0 ? x : -x;
    return x + y;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s[0] >> s[1];
        cin >> e[0] >> e[1];
        cout << slove() << "\n";
    }
    return 0;
}