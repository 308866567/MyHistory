#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string x;
    getchar();
    getline(cin , x,'\n');
    // x+=' ';
    char ans[102][1005];
    memset(ans,' ',sizeof(ans));
    int k = 0;
    int lie=ceil(1.0*x.size() / n);
    for (int i = lie-1; k < x.size(); i--)
    {
        for (int j = 0; j < n&&k < x.size(); j++)
        {
            ans[j][i] = x[k];
            k++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
    return 0;
}