#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string pat = "ababc"; //ģ�崮,��ҪѰ�ҵ��ַ���
string txt;           //�ܴ�
int *n;
int N, M;
// next��ʾ��һ��ƥ��ʧ�ܺ�ģʽ�����������ƶ�����󲽳�
void NEXT() //��ֵnext����
{
    // n.resize(M + 1, 0); // pat��M���ַ�
    int k = -1, j = 0; // k��ʾ��ǰ״̬,j��ʾ��ǰ�ַ�λ��,-1<=k<M
    n[0] = -1;          // next+1��ʾǰ׺�ͺ�׺��ͬ�ĳ���
    // next��ʾӦ���˵�״̬
    //-1��ʾδƥ�����ַ�,0��ʾƥ����һ���ַ�
    while (j <= M)
    {
        if (k == -1 || pat[j] == pat[k])//-1��ʾûƥ���ϵ����
        {
            ++k;
            ++j;
            n[j] = k;
        }
        else
            k = n[k]; //���˺��״̬����ٴ�ʧ�ܻ��˵�����
    }
    // for (int i : n)
    // {
    //     cout << i << " ";
    // }
    // cout<<endl;
}
int kmpsearch(int begin)
{
    int j = 0; //��ʾƥ���˼����ַ�
    int i = begin;
    while ( i < N)
    {
        if (j==-1||txt[i] == pat[j])
        {
            j++;
            i++;
        }
        else
        {
            j = n[j];//j=-1
        }
        if (j == M)
        {
            cout << i - M + 1 << endl;
            j=n[j];
            // return i - M + 1; //ƥ�䵽���ַ�����ͷ������,�����0��ʼ
        }
    }
    return N;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    cin >> txt >> pat;
    N = txt.size();
    M = pat.size();
    n= new int[M+2]();
    // n.resize(M + 1, 0); // pat��M���ַ�
    NEXT();
    int x = txt.size() - pat.size();
    for (int i = 0; i < x;)
    {
        i = kmpsearch(i);
    }
    for (int i = 1; i <= M; i++) 
    {
        cout << n[i] << " ";
    }
    return 0;
}