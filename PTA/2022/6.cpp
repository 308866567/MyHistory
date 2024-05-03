#include <iostream>
#include <string>
using namespace std;
string s, a;
string ans1, ans2;
void slove(string now, string &temp)
{
    for (int i = 1; i < now.size(); i++)
    {
        if (now[i] % 2 == now[i - 1] % 2)
        {
            temp += max(now[i], now[i - 1]);
        }
    }
    // cout<<temp<<"\n";
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> s;
    cin >> a;
    slove(s, ans1);
    slove(a, ans2);
    if (ans1.compare(ans2)==0)
        cout << ans1;
    else
        cout << ans1 << '\n'
             << ans2;
    // cout<<s<<"\n";
    // cout<<a;
    return 0;
}