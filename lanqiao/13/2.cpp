#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
ll m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool f(string x)
{
    if (x[1] == x[0] + 1 && x[2] == x[1] + 1)
    {
        return 1;
    }
    else if (x[3] == x[2] + 1 && x[2] == x[1] + 1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    ll ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= m[i]; j++)
        {
            string x;
            if(i<10) x+='0';
             x+= to_string(i);
             if(j<10) x+='0'; 
             x+= to_string(j);
            if (f(x))
            {
                ans++;
                // cout << x << "\n";
            }
        }
    }
    cout << ans;
    return 0;
}