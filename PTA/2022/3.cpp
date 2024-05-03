#include <iostream>
using namespace std;
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int a, b;
    int n, m;
    cin >> n >> m >> a >> b;
    if (a >= n && b >= n)
    {
        printf("%d-Y %d-Y\n", a, b);
        cout << "huan ying ru guan";
    }
    else if (a < n && b >= m)
    {
        printf("%d-Y %d-Y\n", a, b);
        cout << "qing 2 zhao gu hao 1";
    }
    else if (a >= m && b < n)
    {
        printf("%d-Y %d-Y\n", a, b);
        cout << "qing 1 zhao gu hao 2";
    }
    else if (a < n && b < n)
    {
        printf("%d-N %d-N\n", a, b);
        cout << "zhang da zai lai ba";
    }
    else if (a < n && b < m && b >= n)
    {
        printf("%d-N %d-Y\n", a, b);
        cout << "2: huan ying ru guan";
    }
    else if (b < n && a < m && a >= n)
    {
        printf("%d-Y %d-N\n", a, b);
        cout << "1: huan ying ru guan";
    }
    return 0;
}