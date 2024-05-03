#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    ll n;
    cin >> n;
    ll end = sqrt(n) + 5;
    ll len = 0, ans = n + 1;
    for (int i = 2; i < end; i++)
    {
        int N = n;
        int t = i;
        int sum = 0;
        while (N % t == 0)
        {
            N /= t;
            sum++;
            t++;
        }
        if (sum > len)
        {
            len = sum;
            ans = t;
        }
    }
    if (len == 0)
        cout << 1 << '\n';
    else 
        cout << len << "\n";
    for (int i = ans - len; i < ans; i++)
    {
        cout << i;
        if (i < ans - 1)
            cout << "*";
    }
    return 0;
}