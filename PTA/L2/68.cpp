#include <iostream>
#include <vector>
using namespace std;
const int N = 1001;
int n;
int arr[N];
bool f = 0;
vector<int> ans;
int dfs(int s, int e)
{
    if (s == e) // ����Ҷ�ӽڵ�
    {
        return 1;
    }
    // Ѱ�ҵ�һ�����ڸ��ڵ����
    int l = s+1, r = e;
    int t = e - s + 1;
    while (t--)
    {
        if (arr[l] < arr[s])
            l++;
        if (arr[r] >= arr[s])
            r--;
    }
    if (l < r)
    {
        f = 1;
        return -1;
    }
    dfs(s+1, l);
    dfs(r+1, e);
    ans.push_back(s);
    return 0;
}
int main()
{
    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dfs(0, n - 1);
    for (int i : ans)
        cout << i << ' ';
    return 0;
}