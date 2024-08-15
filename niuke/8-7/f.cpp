#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll n, m;
vector<ll> nums;
void solve()
{
    ll ans = 0;
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch < '0' || ch > '9')
            continue;
        ll sum = 0;
        while (ch >= '0' && ch <= '9')
        {
            sum = sum * 10 + ch - '0';
            ch=getchar();
        }
        nums.push_back(sum);
        ans += sum;
    }
    sort(nums.begin(), nums.end());
    for (ll i = nums.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << nums[i] << "\n";
            break;
        }
        cout << nums[i] << "+";
    }
    cout << ans << "\n";
}

int main()
{
#ifdef LOCAL
    freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
#ifdef LOCAL_WIN
    freopen("C:/Users/30886/Desktop/in.txt", "r", stdin);
#endif
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
