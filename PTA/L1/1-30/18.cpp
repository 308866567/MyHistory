#include <iostream>
using namespace std;
bool used[10] = {0};
int a[10] = {0};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    string x;
    cin >> x;
    int size = x.size();
    for (int i = 0; i < size; i++)
    {
        int t = x[i] - '0';
        used[t] = 1;
    }
    int j = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (used[i])
        {
            a[i] = j;
            j++;
        }
    }
    cout<<"int[] arr = new int[]{";
     for (int i = 9,t=0; i >= 0; i--)
    {
        if (used[i])
        {
            cout<<i;
            t++;
            if(t<j-1)cout<<',';
        }
    }
    cout<<"};\nint[] index = new int[]{";
    for (int i = 0; i < size; i++)
    {
        int t = x[i] - '0';
        cout << a[t];
        if (i < size - 1)
        {
            cout  << ',';
        }
    }
    cout<<"};";
    return 0;
}