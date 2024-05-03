#include <bits/stdc++.h>
using namespace std;
class UF
{
private:
    // ��ͨ��������
    int count;
    //���ڵ�����
    int *parent;
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
        int rootP = find(p);
        int rootQ = find(q);
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
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]]; //·��ѹ������С�߶�
            x = parent[x];
        }
        return x;
    }

public:
    int count()
    {
        return count; /* ���ص�ǰ����ͨ�������� */
    }
};
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;
        int n = board[0].size();  //��
        int m = board.size() / n; //��d
        UF uf;
        uf.uf(m * n + 1);
        int dummy = m * n;
        // �������� d ���������������ĳ����ַ�
        int d[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (int i = 1; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
                if (board[i][j] == 'O')//������㿪ʼ����// ���� O ���������ҵ� O ��ͨ
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (board[x][y] == 'O')
                            uf.un(x * n + y, i * n + j);
                    }
    }
};