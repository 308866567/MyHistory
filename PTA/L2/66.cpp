#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
const int N = 1e5 + 2;
unordered_map<int, bool> used;
int key[N];
int Next[N];
int s, n;
void outadd(int a)
{
	if(a==-1){
		cout<<-1;return;
	}
	for (int i = 10000; i > 0; i /= 10)
	{
		if (i > a)
			cout << "0";
	}
	if (a)
		cout << a;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	cin >> s >> n;
	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c; // 地址 键值 下一个结点
		key[a] = b;
		Next[a] = c;
	}
	int now = s;
	int ds = -1;
	int dn;
	int nadd;
	int k;
	// 去重
	//	used[abs(key[now])] = 1;
	while (now != -1)
	{
		nadd = Next[now];
		k = abs(key[nadd]);
		used[k];
		if (used[k]) // 去重下一个节点,,更改当前节点的下一跳
		{
			if (ds != -1)
			{
				Next[dn] = Next[now];
				dn = Next[now];
			}
			else // 创建头节点
			{
				ds = Next[now];
				dn = ds;
			}
			if (Next[now] != -1)
				Next[now] = Next[nadd];
		}
		else
		{
			used[k] = 1;
		}
		outadd(now);
		cout << " " << key[now] << " " ;//<< Next[now] << "\n";
		outadd(Next[now]);
		cout << "\n";
		now = Next[now];
	}
	//	cout << "\n";
	dn = ds;
	while (dn != -1)
	{
		outadd(dn);
		cout << " " << key[dn] << " ";
		outadd(Next[dn]);
		cout << "\n";
		dn = Next[dn];
		// TODO
	}
	// 输出答案
	//	for (int i = 0; i < n; i++)
	//	{
	//		// 地址补0
	//		cout << now << " " << key[now] << " " << Next[now] << "\n";
	//	}

	// key-address,多个
	// address-size
	return 0;
}