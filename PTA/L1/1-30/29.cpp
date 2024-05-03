#include <iostream>
using namespace std;
int main()
{
    int x;
    int i = 1;
    while (cin >> x)
    {
        if (x == 250)
        {
            cout << i;
            return 0;
        }
        i++;
        /* code */
    }

    return 0;
}