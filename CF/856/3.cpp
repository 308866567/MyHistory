#include <iostream>
using namespace std;
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int arr[n + 1];
        int ans[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = n; i > 0; i--)
        {
            int sum = 1;
            int j = i;
            if (arr[i] == arr[i + 1] && i < n) // 和上一位相等,继承ans
            {
            }
            while (j > 1 && arr[j - 1] >= sum + 1)
            {
                j--;
                sum++;
            }
            // for (; j >= i; j--)
            // {
            ans[i] = sum;
            sum--;
            // }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}