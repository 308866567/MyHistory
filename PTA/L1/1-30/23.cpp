#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s, n;
bool f(int now)
{
    bool used[10] = {0};
    if (now < 1000)
        used[0] = 1;
    int t;
    while (now)
    {
        t = now % 10;
        now /= 10;
        used[t] = 1;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (used[i])
            sum++;
    }
    return sum == n;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> s >> n;
    for (int i = s;; i++)
    {
        if (f(i))
        {
            cout << i - s << ' ';
            if (i < 1000)
                cout << 0;
            if (i < 100)
                cout << 0;
            if (i < 10)
                cout << 0;
            cout << i;
            return 0;
        }
    }
    return 0;
}