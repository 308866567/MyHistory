#include <iostream>
using namespace std;
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    char x;
    cin >> n >> x;
    getchar();
    string arr;
    getline(cin,arr,'\n');
    int size = arr.size();
    if (n > size)
    {
        for (int i = 0; i < n - size; i++)
        {
            cout << x;
        }
    }
    for (int i =  size-n; i < size; i++)
    {
        cout << arr[i];
    }
    return 0;
}