#include <iostream>
using namespace std;
string a[11];
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    a[0] = "ling", a[1] = "yi", a[2] = "er", a[3] = "san";
    a[4] = "si", a[5] = "wu", a[6] = "liu", a[7] = "qi";
    a[8] = "ba", a[9] = "jiu";
    a[10] = "fu";
    string t;
    cin >> t;
    int size = t.size();
    for (int i = 0; i < size; i++)
    {
        if (t[i] == '-')
        {
            cout << a[10] << ' ';
            continue;
        }
        else
            cout << a[(int)(t[i] - '0')];
        if (i < size - 1)
            cout << ' ';
    }
    return 0;
}