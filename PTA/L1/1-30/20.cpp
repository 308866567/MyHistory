#include <iostream>
#include <vector>
using namespace std;
struct stu
{
    bool f;
    string name;
} s[51];
int n;
bool used[51] = {0};

void f(bool a)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i].f == a || used[i])
            continue;
        else
        {
            cout << s[i].name;
            used[i]=1;
            return;
        }
    }
    return;
};

int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n;
    int size = n / 2;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].f >> s[i].name;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        cout << s[i].name << ' ';
        f(s[i].f);
        if (i < size - 1)
            cout << '\n';
    }
    return 0;
}