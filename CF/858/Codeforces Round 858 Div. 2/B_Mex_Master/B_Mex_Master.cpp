#include <iostream>
using namespace std;
int arr[20005];
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
        int used[20005] = {};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            used[arr[i]]++;
        }
        if (used[0] == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        else if (used[1] == 0 && used[0] != 0)
        {
            cout << 1 << "\n";
            continue;
        }
        // 0��1����
        // ��Ҫ��used[0]-1���ղŲ�����ϳ�0
        if (n - used[0] >= used[0] - 1) // ���0�����
        {
            cout << 0 << "\n";
            continue;
        }
        //��ϳ�0�����,ʹ1����ϳ���
        else if(n - used[1] >= used[1] - 1)
        {
            cout << 1 << '\n';
            continue;
        }
    }
    return 0;
}