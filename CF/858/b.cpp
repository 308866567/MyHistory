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
        // ��Ҫ��used[0]-1���ղŲ�����ϳ�0
        if (n - used[0] >= used[0] - 1) // ���0�����
        {
            cout << 0 << "\n";
            continue;
        }
        //
        else if(n - used[1]-used[0] >= used[1] - 1)
        {
            cout << 1 << '\n';
            continue;
        }
        else 
            cout<<2<<'\n';
    }
    return 0;
}