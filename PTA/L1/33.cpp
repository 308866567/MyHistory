#include <iostream>
using namespace std;
class man
{
public:
    string name;
    int a;
    int b;
    man()
    {
        cin >> name >> a >> b;
        t();
    }
    bool t()
    {
        if (a < 15 || a > 20 || b < 50 || b > 70)
        {
            cout << name << "\n";
            return 0;
        }
        else
            return 1;
    }
};
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin>>n;
    man arr[n];
    return 0;
}