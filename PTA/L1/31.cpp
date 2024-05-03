#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    string x;
    int i = 1;
    while (cin >> x)
    {
        if (x == "End")
            return 0;
        if (i > k)
        {
            i = 0;
            cout << x << "\n";
        }
        else if (x == "ChuiZi")
        {
            cout << "Bu"
                 << "\n";
        }
        else if (x == "Bu")
        {
            cout << "JianDao"
                 << "\n";
        }
        else if (x == "JianDao")
        {
            cout << "ChuiZi"
                 << "\n";
        }
        i++;
    }

    return 0;
}