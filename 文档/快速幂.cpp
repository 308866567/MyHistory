#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long quick(long long a, long long b)
{
    // ԭ��:����� a �Գ�һ�Σ��ͻ��� a^2 ��
    // �ٰ� a^2 �Գ�һ�ξͻ��� a^4 ��
    // Ȼ���� a^8���� �Գ� n �εĽ���� a^{2^n}
     long long ans =1;   //���
    long long base = a; //��
    while (b > 0)       //��b���2����
    {
        if (b & 1) //���b���һλ��1,����a^{2^x}
        {
            ans *= base;//a^x*a^y=a^{x+y}
        }
        base *= base; // 1,2,4,8��ǰ����a�ļ�����
        b >>= 1;      // b������һλ
        //ȡ������
        // ans %= p;
        // base %= p;
    }
    return ans;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    long long a, b, p, t;
    cin >> a >> b >> p;
    long long ans = a;
    long long base = a; //��
    ans = 1;            //���
    t = b;
    while (b > 0) //������
    {
        if (b & 1) //���һλ��1
        {
            ans *= base;
        }
        base *= base; // 1,2,4,8
        b >>= 1;      // b������һλ
        //ȡ������
        ans %= p;
        base %= p;
    }
    printf("%lld^%lld mod %lld=%lld", a, t, p, ans);
    return 0;
}