#include <bits/stdc++.h>
using namespace std;
struct MAN
{
	struct MAN *next = NULL; //ͬ��ŵ�������һ��
	long a = -1;			 //ֵ,δ����ϣ��,С�������
	struct MAN *p;			 //���ڵ�Ľṹ��,��ʼΪ�Լ�
	MAN()
	{
		next = NULL;
		a = -1;
		p = NULL;
	}
};
vector<struct MAN> arr; //�洢С����
class UF
{
public:
	UF go(long n) /* ���캯����n ΪС�������� */
	{
		arr.resize(n + 2, MAN());
	};
	struct MAN *ha(long a) //������ϣ,����һ��С����,�������λ��
	{
		long h = a % 1000001; //���ת��
		if (arr[h].a == -1)	  //���û�г��ֹ�
		{
			arr[h].a = a;
			arr[h].p = &arr[h];
			return &arr[h];
		}
		else if (arr[h].a != a && arr[h].a != -1) //��������
		{
			struct MAN *x = arr[h].next;
			while (x != NULL)
			{
				x = x->next;
			}
			x = new struct MAN;
			x->a = a;
			x->next = NULL;
			x->p = x;
			return x;
		}
		else if (arr[h].a == a) //����ҵ�
		{
			return &arr[h];
		}
		return NULL;
	}
	void lian(struct MAN *p, struct MAN *q) //��ͨ������
	{
		struct MAN *rootP = find(p);
		struct MAN *rootQ = find(q);
		if (rootP == rootQ)
			return;
		rootP->p = rootQ; // �ϲ����ڵ�
	}
	struct MAN *find(struct MAN *x) /* ����:����ĳ���ڵ� x �ĸ��ڵ� */
	{
		// ���ڵ�� x.p == x,ÿ��ѭ����������һ��
		while (x->p != x)
		{
			x->p = (x->p)->p; //·��ѹ������С�߶�
			x = x->p;
		}
		return x;
	}
};
vector<long> diren;
int main()
{
	// freopen("in.txt", "r", stdin);
	long n, t;
	scanf("%ld", &t); // t������
	long b;
	long x, y;
	for (int ii = 0; ii < t; ii++)
	{
		scanf("%ld", &n);
		UF yuan;
		yuan.go(1000093);
		for (int i = 0; i < n; i++)
		{
			scanf("%ld %ld %ld", &x, &y, &b);
			// cin >> x >> y >> b;
			if (b == 1) //��ͨ
			{
				yuan.lian(yuan.ha(x), yuan.ha(y));
			}
			else //���ͳһ�ж�,�洢x��y
			{
				diren.push_back(x);
				diren.push_back(y);
				//�ж��Ƿ�Ϊ���ѣ�����Ǿ�no
				continue;
			}
		}
		int i;
		bool f = false;
		for (i = 0; i < diren.size(); i++)
		{
			struct MAN *rootP = yuan.find(yuan.ha(diren[i]));
			struct MAN *rootQ = yuan.find(yuan.ha(diren[++i]));
			if (rootP->p == rootQ->p)
			{
				f = true;
				cout << "NO" << endl;
				diren.clear();
				arr.clear();
				break;
			}
		}
		if (!f)
			cout << "YES" << endl;
		diren.clear();
		arr.clear();
	}
	return 0;
}