#include <stdio.h>
int main(void)
{
    char a[10];
    int b;
    int s;
    // s=scanf("%d",&b);
    // printf("=%d",s);//�ַ����ŵ���0�����ֵ���1���س��ո񲻹�
    for (int i = 0; i < 4; i++)
    {
        while (scanf("%s", &a) != 0)
        {
            printf("%s\n", a);
        }
    }

        // string a;
	// char name[256];
    // cin.getline(name, 256,' ');
    // cin.getline(a,222);
    // cout<<name;
}