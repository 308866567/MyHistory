#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, s;
int ans = 0;
vector<int> arr[117]; // 存储PTA成绩
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> k >> s;
    int ta, tb;
    for (int i = 0; i < n; i++)
    {
        cin >> ta >> tb;
        if (ta >= 175)
        {
            if(tb>=s) ans++;
            else
            arr[ta - 175].push_back(tb);
        }
    }
    for (int i = 0; i < 117; i++)
    {
        sort(arr[i].begin(), arr[i].end(), cmp); // 从小到大
    }
    // 先推荐一轮无PTA成绩
    // 再把所有大于s的推荐上去
    for (int i = 0; i < k; i++) // 推荐k次
    {
        for (int j = 0; j < 117; j++) // 倒序
        {
            for (int k = arr[j].size() - 1; k >= 0; k--)
            {
                    ans++;
                    // cout<<j+175<<'-'<<arr[j][k]<<' ';
                    arr[j].pop_back();
                    break;
            }
        }
        // cout<<"\n";
    }
    cout<<ans;
    return 0;
}