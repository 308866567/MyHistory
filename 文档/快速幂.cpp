#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long quick(long long a, long long b)
{
    // 原理:如果将 a 自乘一次，就会变成 a^2 。
    // 再把 a^2 自乘一次就会变成 a^4 。
    // 然后是 a^8…… 自乘 n 次的结果是 a^{2^n}
     long long ans =1;   //结果
    long long base = a; //幂
    while (b > 0)       //把b拆成2进制
    {
        if (b & 1) //如果b最后一位是1,加上a^{2^x}
        {
            ans *= base;//a^x*a^y=a^{x+y}
        }
        base *= base; // 1,2,4,8当前所在a的几次幂
        b >>= 1;      // b向右移一位
        //取余运算
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
    long long base = a; //幂
    ans = 1;            //结果
    t = b;
    while (b > 0) //快速幂
    {
        if (b & 1) //最后一位是1
        {
            ans *= base;
        }
        base *= base; // 1,2,4,8
        b >>= 1;      // b向右移一位
        //取余运算
        ans %= p;
        base %= p;
    }
    printf("%lld^%lld mod %lld=%lld", a, t, p, ans);
    return 0;
}