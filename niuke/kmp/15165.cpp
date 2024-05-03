#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string pat = "ababc"; //模板串,需要寻找的字符串
string txt;           //总串
int *n;
int N, M;
// next表示在一次匹配失败后模式串可以往后移动的最大步长
void NEXT() //赋值next数组
{
    // n.resize(M + 1, 0); // pat有M个字符
    int k = -1, j = 0; // k表示当前状态,j表示当前字符位置,-1<=k<M
    n[0] = -1;          // next+1表示前缀和后缀相同的长度
    // next表示应回退的状态
    //-1表示未匹配上字符,0表示匹配了一个字符
    while (j <= M)
    {
        if (k == -1 || pat[j] == pat[k])//-1表示没匹配上的情况
        {
            ++k;
            ++j;
            n[j] = k;
        }
        else
            k = n[k]; //回退后的状态如果再次失败回退到哪里
    }
    // for (int i : n)
    // {
    //     cout << i << " ";
    // }
    // cout<<endl;
}
int kmpsearch(int begin)
{
    int j = 0; //表示匹配了几个字符
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
            // return i - M + 1; //匹配到的字符串开头的索引,数组从0开始
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
    // n.resize(M + 1, 0); // pat有M个字符
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