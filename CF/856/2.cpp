#include <iostream>
using namespace std;
bool bf(long a, long b) // a能被b整除
{
    double x = 1.0*a / b;
    long y = a / b;
    if (x == y) // 整除
        return 1;
    else
        return 0; // 不能整除
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    int n;
    long arr[10005];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
                arr[i]++;
        }
        for (int i =0; i <n; i++)
        {
            if (bf(arr[i], arr[i - 1]))
            {
                arr[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}