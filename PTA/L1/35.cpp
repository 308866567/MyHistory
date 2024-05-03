#include <iostream>
#include <vector>
using namespace std;
int n;
int sch[101];//每个学校的队伍数
vector <int>ans[101];//首位表示已经分配座位的人数
bool used[101];
int S = 0;
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> sch[i];
		sum += sch[i];
		ans[i].push_back(0);
	}
	//一个学校一次确定一个座位号
	int now = 1; //当前学校
	int I = 1;
	for (; I <= sum*10 && S < n - 1; I++)
	{
		//确定学校
		while (used[now])//排除安排完的学校
		{
			now++;
		if (now >n)
			now = 1;
		}
		//分配座位
		ans[now].push_back(I);
		ans[now][0]++;
		if (ans[now][0] == sch[now] * 10)
		{
			used[now] = 1;
			S++;
		}
		now++;
		if (now > n)
			now = 1;
	}
	//可能会剩最后一只队伍
	int t = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			t = i;
			break;
		}
	}
	//对最后一只队伍进行隔位就坐
	while (ans[t][0] < sch[t] * 10)
	{
		ans[t].push_back(I);
		ans[t][0]++;
		I += 2;
	}
	for(int i=1;i<=n;i++){
		cout<<"#"<<i<<"\n";
		for(int j=1;j<ans[i].size();j++){
			cout<<ans[i][j];
			if(j%10) cout<<" ";
		if(!(j%10)&&!(i==n&&j==ans[i].size()-1))cout<<"\n";
		}
	
	}
	return 0;
}
