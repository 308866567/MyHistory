// շת������������Լ����һ�ַ�����
// ���ľ��������ǣ��ý�С�����ϴ�����
// ���ó��ֵ���������һ������ȥ�����������ó��ֵ��������ڶ�������ȥ����һ��������˷�����ֱ�����������0Ϊֹ��
// ������������������Լ������ô���ĳ��������������������Լ��

// ͬ�������С��������ֻҪ�����������ĳ˻����������������
// printf(��lcm=%d\n��,a*b/gcd(a,b)��

// Gcd(a,b) = gcd(b,a mod b)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
ll gcd(ll a,ll b) {
	return b==0?a:gcd(b,a%b);
}
