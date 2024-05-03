#include <iostream>
using namespace std;
bool used[300] = {0};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    string a;
    getline(cin, a, '\n');
    // char-int
    string x;
    getline(cin, x, '\n');

    int size = x.size();
    for (int i = 0; i < size; i++)
    {
        used[(int)x[i]] = 1;
    }
    size = a.size();
    for (int i = 0; i < size; i++)
    {
        if (used[(int)a[i]])
            continue;
        else
            cout << a[i];
    }
    return 0;
}