#include <cstdio>
#include <cstring>
#define N 150005
#define M 1005

char a[M][M], b[M];  //�����Ѹ�ֵ
int Hash[N], Hash_b;
int pos[N][15], cur[N];
//��a�в����ַ���b
//�涨�ַ���b�����Ϊ1000

/*
�ַ�����ϣ��
    - ���ַ��������ֵ
    - ����ֵ��Ϊ�±괢��
    - ����ʱֱ�Ӹ��ݼ�ֵ�����ַ����Ƿ���ڼ���
*/
int main() {
    int len1, len2;
    int mod1 = 133337, mod2 = 333377;
    int Hash1, Hash2;
    for (int i = 0; i < 10000; ++i) {
        scanf("%s", a[i]);
        len1 = strlen(a[i]), Hash[i] = 1;
        for (int j = 0; j < len1; ++j) {  // �����ֵ
            Hash1 = (a[i][j] + Hash1 * 131 % mod1) % mod1;
            // Hash2 = (a[i][j] + Hash2 * mod2 % mod1) % mod1;
        }
        Hash[Hash1] = 1;
        pos[Hash1][cur[Hash1]] = i + 1;
        cur[Hash1]++;
        /*
            while(Hash[Hash1]!=0){
                Hash1 = (a[i][j] + Hash1 * 131 % mod1) % mod1;
                Hash2 = (a[i][j] + Hash2 * mod2 % mod1) % mod1;
            }
            Hash[Hash1] = Hash2;
        */
    }

    /*
        abccd
        Hash[i] = 97+1*13
        Hash[i] = (97+1*13)+(98+2*13)

        ab
        Hash = 97+1*13
        Hash = (97+1*13)+(97+1*13*13+98)
        ba
        Hash = 98+1*13
        Hash = (98+1*13)+(98+1*13*13+97)

        ��������Ĺ�ϣֱֵ����Ϊ�±�
    */
    // Hash[(97 + 1 * 13) + (97 + 1 * 13 * 13 + 98)];

    for (int i = 0; i < len2; ++i) {
        Hash_b += (b[i] + Hash_b * 131 % mod1) % mod1;
    }

    for (int i = 0; i < 10000; ++i) {
        scanf("%s", b);
        len2 = strlen(b);
        for (int i = 0; i < len2; ++i) {
            Hash_b += (b[i] + Hash_b * 131 % mod1) % mod1;
        }
        if (Hash[Hash_b] != 0)
            printf("%d\n", Hash[Hash_b] - 1);
    }

    // for (int i = 0; i < 10000; ++i) {
    //     if (Hash[i] == Hash_b) {
    //         printf("exist\n");
    //         break;
    //     }
    // }
}