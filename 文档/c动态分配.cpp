#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int main(void)
{
    printf("go\n");
    int *a = (int *)malloc(2 * sizeof(int));
    int *b = (int *)calloc(0, 2 * sizeof(int));
    //     size_t�޷�������
    //     sizeof,��ȡ������ռ�õ��ڴ�ռ��ֽ���,��������size_t;sizeof ��һ���������
    //     1.����һ�����,��ʽ2��:sizeof a �� sizeof(a);
    //     2.������������,����ʹ�ô����ŵķ�ʽ,��sizeof(int).
    //     sizeof�����������ض�̬������ڴ�ռ�Ĵ�С
    //     strlen,��ȡ�ַ�����ʵ��ʹ�õ��ֽ���,�����������β��'\0',��������size_t;
    //     size(),
    free(a);
    free(b);
    char c[]="abcde";//��һ��\0�Ŀռ�
    printf("%d",sizeof(c)/sizeof(char));
    printf("\n%d",strlen(c));//����Ԫ�ظ�����ȥ��\0
    return 0;
}