#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int flag = 0;
        int tl = 0, tz = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
                tl++; // 0����
            else
            {
                tz++; // ��0�ĸ���
                if (x > 1)
                    flag = 1; // ���ִ���1����
            }
        }
        if (tl <= tz + 1)//0�Ŀտ��Ա�����
            cout << 0 << endl;
        else//һ������ϳ�0
        {
            if (flag || !tz)//���ִ���1�Ļ��߷�0���ĸ�����Ϊ0
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}