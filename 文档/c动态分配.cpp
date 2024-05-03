#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int main(void)
{
    printf("go\n");
    int *a = (int *)malloc(2 * sizeof(int));
    int *b = (int *)calloc(0, 2 * sizeof(int));
    //     size_t无符号整型
    //     sizeof,获取操作数占用的内存空间字节数,返回类型size_t;sizeof 是一个运算符。
    //     1.对于一般变量,形式2种:sizeof a 或 sizeof(a);
    //     2.对于数据类型,必须使用带括号的方式,如sizeof(int).
    //     sizeof不能用来返回动态分配的内存空间的大小
    //     strlen,获取字符数组实际使用的字节数,不包含数组结尾符'\0',返回类型size_t;
    //     size(),
    free(a);
    free(b);
    char c[]="abcde";//多一个\0的空间
    printf("%d",sizeof(c)/sizeof(char));
    printf("\n%d",strlen(c));//返回元素个数，去掉\0
    return 0;
}