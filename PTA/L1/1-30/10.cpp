#include <iostream>
using namespace std;
int n;
long long sum = 1;
long long ans=0;
void dfs(int now)
{
    if (now > n)
        return;
    sum *= now;
    ans+=sum;
    dfs(now + 1);
    return;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n;
    dfs(1);
    cout<<ans;
    return 0;
}