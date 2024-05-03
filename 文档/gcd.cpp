// 辗转相除法是求最大公约数的一种方法。
// 它的具体做法是：用较小数除较大数，
// 再用出现的余数（第一余数）去除除数，再用出现的余数（第二余数）去除第一余数，如此反复，直到最后余数是0为止。
// 如果是求两个数的最大公约数，那么最后的除数就是这两个数的最大公约数

// 同理计算最小公倍数：只要用这两个数的乘积除以最大公因数即可
// printf(“lcm=%d\n”,a*b/gcd(a,b)）

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
