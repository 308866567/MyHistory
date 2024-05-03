#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class KMP
{
public:
    string p = " ababc", s = " abababc";
    vector<int> ne;
    KMP(int a)
    {
        cin >> p; // ģ�崮
        cin >> s;
        ne.resize(p.size());
    }
    void create() // ��next
    {
        return;
    }
    void kmp() // �±��1��ʼ
    {
        int len = s.size();
        int n = p.size() - 1;
        int j = 0;
        for (int i = 0; i < len; i++)
        {
            while (j != 0 && s[i] != p[j + 1])
            {
                j = ne[j];
            }
            if (s[i] == p[j + 1])
                j++;
            if (j > n)
            {
                cout << i - n;
                j = ne[j]; // Ѱ����һ��}
            }
        }
    }
};
