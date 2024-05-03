#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int flag = 0;
        int tl = 0, tz = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
                tl++; // 0个数
            else
            {
                tz++; // 非0的个数
                if (x > 1)
                    flag = 1; // 出现大于1的数
            }
        }
        if (tl <= tz + 1)//0的空可以被插满
            cout << 0 << endl;
        else//一定会组合出0
        {
            if (flag || !tz)//出现大于1的或者非0数的个数不为0
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}