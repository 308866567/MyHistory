#include <iostream>
using namespace std;
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    string a, b, x;
    int size = 0;
    while (1)
    {
        cin >> x;
        size++;
        if (size == 2)
            a = x;
        if (size == 14)
            b = x;
        if (x == ".")
            break;
    }
    if (size <= 2)
        cout << "Momo... No one is for you ...";
    else if (size <= 14)
        cout << a << " is the only one for you...";
    else
        cout << a << " and " << b << " are inviting you to dinner...";
    return 0;
}