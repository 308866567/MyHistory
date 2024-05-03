#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f[1002] = {0};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    int k;
    int maxx;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        int t;
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            f[t]++;
        }
    }
    for (int i = 1; i < 1001; i++)
    {
        if (f[i] >= f[maxx])
        {
            maxx = i;
        }
    }
    cout<<maxx<<' '<<f[maxx];
    return 0;
}