#include <iostream>
using namespace std;
long long ans = 1, maxx;
void slove(int now)
{
    if (now > maxx)
        return ;
    ans *= now;
    slove(now+1);
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int a, b;
    cin >> a >> b;
    maxx = a + b;
    slove(1);
    cout<<ans;
    return 0;
}