#include <bits/stdc++.h>
using namespace std;
class UF
{
private:
    int count;   // ��ͨ��������
    int *parent; //���ڵ�����
    // int *size; // ����һ�������¼���ġ�������
public:
    UF uf(int n) /* ���캯����n Ϊͼ�Ľڵ����� */
    {
        count = n;
        parent = new int[n]; // �洢ÿ���ڵ�ĸ��ڵ�
        // ���ÿ����ֻ��һ���ڵ�
        // size = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // ���ڵ�ָ���ʼָ���Լ�
            // size[i] = 1;   // ����Ӧ�ó�ʼ�� 1
        }
    };

public:
    void un(int p, int q) //��ͨ������
    {
        int rootP = find(p); // p�ĸ��ڵ��±�
        int rootQ = find(q); // q�ĸ��ڵ��±�
        if (rootP == rootQ)
            return;
        // С���ӵ��������棬��ƽ��
        // if (size[rootP] > size[rootQ])
        // {
        //     parent[rootQ] = rootP;
        //     size[rootP] += size[rootQ];
        // }
        // else
        // {
        //     parent[rootP] = rootQ;
        //     size[rootQ] += size[rootP];
        // }
        parent[rootP] = rootQ; // ���������ϲ�Ϊһ��
        count--;               // ���������϶�Ϊһ
    }

private:
    int find(int x) /* ����:����ĳ���ڵ� x �ĸ��ڵ� */
    {
        // ���ڵ�� parent[x] == x,ÿ��ѭ����������һ��
        while (parent[x] != x) //���ڵ�ĸ��ڵ�Ϊ�Լ�����
        {
            // ÿ�� while ѭ�������һ�Զ����ӽڵ�ĵ�ͬһ��
            //һ��ֻ����һ��,�޸�һ���ڵ�ĸ��ڵ�
            parent[x] = parent[parent[x]]; //·��ѹ������С�߶�
            x = parent[x];
        }
        return x;
    }
    // int find(int x)//�����·��ѹ��д��,
    // {   //�ݹ�д�����·�ϵ����нڵ��Ƶ����ڵ���
    //     //�� x �����ڵ�֮������нڵ�ֱ�ӽӵ����ڵ�����
    //     if (parent[x] != x)
    //     {
    //         parent[x] = find(parent[x]);
    //     }
    //     return parent[x];
    // }
public:
    int count()
    {
        return count; /* ���ص�ǰ����ͨ�������� */
    }
};