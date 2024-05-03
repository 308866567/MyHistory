#include <iostream>
using namespace std;
bool bf(string &x)
{
    int l = 0;
    int r = x.size() - 1;
    while (l < r)
    {
        if (x[l] != x[r])
        {
            cout << "NO";
            return 0;
        }
        l++;
        r--;
    }
    cout << "YES";
    return 1;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    int n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        string arr[40];
        int max1=0, max2=0;
        int min1=0, min2=0;
        for (int i = 0; i < 2 * n - 2; i++)
        {
            cin >> arr[i];
            if (arr[i].size() == arr[max1].size())
            {
                max2 = i;
            }
            else if (arr[i].size() > arr[max1].size()) // 找最长串
            {
                max1 = i;
            }
            if (arr[i].size() == arr[min1].size())
            {
                min2 = i;
            }
            else if (arr[i].size() < arr[min1].size()) // 找最短串
            {
                min1 = i;
            }
        }
        // if (arr[max1][1] == arr[max2][0])
        if (arr[max1][0] == arr[min1][0]) // 开头相等,1是前缀
        {
            // arr[max1].push_back(arr[max2][s2 - 1]);
            arr[max1].push_back(arr[min2][0]);
            // cout << arr[max1] << "1 ";
            bf(arr[max1]);
        }
        else if (arr[max1][0] == arr[min2][0])
        {
            // arr[max2].push_back(arr[max1][s1 - 1]);
            arr[max1].push_back(arr[min1][0]);
            // cout << arr[max1] << "2 ";
            bf(arr[max1]);
        }
        else if (arr[max2][0] == arr[min1][0])
        {
            // arr[max2].push_back(arr[max1][s1 - 1]);
            arr[max2].push_back(arr[min2][0]);
            // cout << arr[max2] << "3 ";
            bf(arr[max2]);
        }
        else if (arr[max2][0] == arr[min2][0])
        {
            // arr[max2].push_back(arr[max1][s1 - 1]);
            arr[max2].push_back(arr[min1][0]);
            // cout << arr[max2] << "4 ";
            bf(arr[max2]);
        }
        cout << '\n';
    }
    return 0;
}