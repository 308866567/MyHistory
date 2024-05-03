#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ans[11] = {};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    char x;
    while (cin >> x)
    {
        ans[x - '0']++;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (ans[i] == 0)
            continue;
        else
        {
            cout << i << ':' << ans[i];
            // if (i < 9)
                cout << '\n';
        }
    }
    return 0;
}