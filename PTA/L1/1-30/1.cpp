#include <iostream>
#include <cmath>
using namespace std;
int n;
char x;
int maxx;                       // ����ĸ���
void out(int now, int a, int b) // ��ǰnow��
{

    for (int i = 0; i < a; i++) // �ո�
    {
        cout << ' ';
    }
    if (now == 1)
    {
        cout << x << "\n";
        return;
    }
    for (int i = 0; i < b; i++)
    {
        cout << x;
    }
    cout << '\n';
    out(now - 1, a + 1, b - 2);
    for (int i = 0; i < a; i++) // �ո�
    {
        cout << ' ';
    }
    for (int i = 0; i < b; i++)
    {
        cout << x;
    }
      cout << '\n';
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> x;
    int ans = sqrt((n + 1) / 2); // ans*2-1Ϊ�ܲ���,ans-1Ϊ�ϰ벿��
    maxx = 1 + (ans - 1) * 2;
    // ����������ɵ�����ɳ©��״,(1+3+5+..)*2-1
    // cout << maxx << '\n';
    out(ans, 0, maxx);
    cout<<n-(ans*ans*2-1);
    return 0;
}