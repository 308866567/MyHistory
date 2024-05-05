#include <stdio.h>
#include <math.h>

double funcos(double e, double x);

int main()
{

#ifdef LOCAL
    freopen("/home/xiaobingdu/code/c++/in.txt", "r", stdin);
#endif
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

/* 你的代码将被嵌在这里 */

double funcos(double e, double x)
{
    int j, b = 1;
    double sum = 0, a, i, c;
    for (i = 0;; i++)
    {
        for (j = 1, c = 1; j <= 2 * i; j++)
        {
            c *= j;
        } // 实行阶乘运算
        a = pow(x, 2 * i) / c; // pow（，）函数为幂函数
        sum += b * a;
        b = -b;
        if (fabs(a) < e) // fabs（）函数为取绝对值函数
            // 此处的fabs（）函数可以省略，因为a不会为负数
            break; // 另起一行进行跳出循环
    }
    return sum;
}
