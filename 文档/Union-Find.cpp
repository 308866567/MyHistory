#include <bits/stdc++.h>
using namespace std;
class UF
{
private:
    int count;   // ��ͨ��������
    int *parent; // ���ڵ�����
public:
    UF(int n) /* ���캯����n Ϊͼ�Ľڵ����� */
    {
        count = n;
        parent = new int[n]; // �洢ÿ���ڵ�ĸ��ڵ�
        // ���ÿ����ֻ��һ���ڵ�
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // ���ڵ�ָ���ʼָ���Լ�
        }
    };

public:
    void un(int p, int q) // ��ͨ������
    {
        int rootP = find(p); // p�ĸ��ڵ��±�
        int rootQ = find(q); // q�ĸ��ڵ��±�
        if (rootP == rootQ)
            return;
        parent[rootP] = rootQ; // ���������ϲ�Ϊһ��
        count--;               // ���������϶�Ϊһ
    }

private:
    int find(int x) /* ����:����ĳ���ڵ� x �ĸ��ڵ� */
    {
        // ���ڵ�� parent[x] == x,ÿ��ѭ����������һ��
        while (parent[x] != x) // ���ڵ�ĸ��ڵ�Ϊ�Լ�����
        {
            // ÿ�� while ѭ�������һ�Զ����ӽڵ�ĵ�ͬһ��
            // һ��ֻ����һ��,
            // x�ڵ�ĸ��׸���Ϊүү
            parent[x] = parent[parent[x]]; // ·��ѹ������С�߶�
            x = parent[x];
        }
        return x;
    }
    // int find(int x)//�����·��ѹ��д��,
    // {   //�ݹ�д�����·�ϵ����нڵ��Ƶ����ڵ���
    //     //�� x �����ڵ�֮������нڵ�ֱ�ӽӵ����ڵ�����
    //     if (parent[x] != x)//û������ڵ�,���������ڵ㿪�ݹ�
    //     {
    //    //���нڵ㶼ֱ���ƶ������ڵ���
    //         parent[x] = find(parent[x]);
    //     }
    //     return parent[x];//���һ��ݹ鷵�ظ��ڵ�
    // }

public:
    int count()
    {
        return count; /* ���ص�ǰ����ͨ�������� */
    }
};