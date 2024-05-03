#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    int h, w;
    int p;
    double d;
    while (n--)
    {
        cin >> h >> w;
        p = (h - 100) * 0.9 * 2;
        d = abs(p - w);
        if (d < 0.1 * p)
            cout << "You are wan mei!";
            else if(w>p) 
            cout << "You are tai pang le!";
            else 
            cout << "You are tai shou le!";
    }

    return 0;
}