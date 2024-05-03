#include <bits/stdc++.h>
using namespace std;
struct MAN
{
	struct MAN *next = NULL; //同序号的链表下一个
	long a = -1;			 //值,未经哈希的,小朋友序号
	struct MAN *p;			 //父节点的结构体,初始为自己
	MAN()
	{
		next = NULL;
		a = -1;
		p = NULL;
	}
};
vector<struct MAN> arr; //存储小朋友
class UF
{
public:
	UF go(long n) /* 构造函数，n 为小朋友总数 */
	{
		arr.resize(n + 2, MAN());
	};
	struct MAN *ha(long a) //拉链哈希,输入一个小朋友,输出他的位置
	{
		long h = a % 1000001; //序号转换
		if (arr[h].a == -1)	  //如果没有出现过
		{
			arr[h].a = a;
			arr[h].p = &arr[h];
			return &arr[h];
		}
		else if (arr[h].a != a && arr[h].a != -1) //查找拉链
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
		else if (arr[h].a == a) //如果找到
		{
			return &arr[h];
		}
		return NULL;
	}
	void lian(struct MAN *p, struct MAN *q) //连通两个量
	{
		struct MAN *rootP = find(p);
		struct MAN *rootQ = find(q);
		if (rootP == rootQ)
			return;
		rootP->p = rootQ; // 合并父节点
	}
	struct MAN *find(struct MAN *x) /* 作用:返回某个节点 x 的根节点 */
	{
		// 根节点的 x.p == x,每次循环往根靠近一个
		while (x->p != x)
		{
			x->p = (x->p)->p; //路径压缩，减小高度
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
	scanf("%ld", &t); // t组数据
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
			if (b == 1) //连通
			{
				yuan.lian(yuan.ha(x), yuan.ha(y));
			}
			else //最后统一判断,存储x和y
			{
				diren.push_back(x);
				diren.push_back(y);
				//判断是否为朋友，如果是就no
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