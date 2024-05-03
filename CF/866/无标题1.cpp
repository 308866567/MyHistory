#include <iostream>
using namespace std;
int s1(string &a)
{
	int size = a.size();
	int ans[size] = {};
	int t,ne;
	for (int i = 0; i < size; i++)
	{
//		t=i,ne=(t-1+size)%size;
		ne=i;
		for (int j = 0; j < size; j++)//对第i列进行计算
		{
			if (a[ne] == '0')
			{
				ans[i] = j;
				break;
			}
//			t--;
			ne=(ne-1+size)%size;
//			if(a[i]=='1'&&a[ne]=='1')
		}
		cout<<ans[i]<<' ';
	}
	//对ans进行处理得答案
	int sum=0;
	return 1;
}

int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	string a;
//	int t;
//	while (t--)
//	{
		cin >> a;
//	}
s1(a);
	return 0;
}
