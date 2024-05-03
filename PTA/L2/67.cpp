#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1001;
double n, d;
struct y
{
    double k;
    double s;
    double d;
} arr[N];
bool cmp(y &a, y &b)
{
    return a.d > b.d;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].k;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].s;
        arr[i].d = 1.0 * arr[i].s / arr[i].k;
    }
    sort(arr, arr + n, cmp);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (d <= 0)
            break;
        else if (d >= arr[i].k)
        {
            d -= arr[i].k;
            ans += arr[i].s;
        }
        else if (d < arr[i].k)
        {
            ans += 1.0 * d / arr[i].k * arr[i].s;
            d = 0;
        }
    }
    printf("%.2lf", ans);
    return 0;
}