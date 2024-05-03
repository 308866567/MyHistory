#include <iostream>
using namespace std;
int n;
int arr[6];
bool used[6][7];
void slove(int now)//第一次
{
    if (now > n)
        return;
    for (int i = 0; i < 6; i++) // 第i个
    {
        for (int j = 6; j > 0; j--) // 数字
        {
            if (used[i][j]!=1)
            {
                arr[i] = j;
                used[i][j] = 1;
                break;
            }
        }
    }
    slove(now+1);
}
int main()
{
    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
        used[i][arr[i]] = 1;
    }
    cin >> n; // 摇n次
    slove(1);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }
    cout<<arr[5]<<"\n";
    return 0;
}