#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
	vector<bool> visit;
	vector<bool> onpath;		  //记录路径
	vector<map<int, bool>> graph; //邻接表
	bool f = 0;					  //是否出现环
	void dfs(int now)			  // now表示第几门课程
	{
		if (onpath[now] ) //出现环
		{
			f = 1;
			return;
		}
		if (visit[now] || f)
		{
			return;
		}
		visit[now] = 1;
		onpath[now] = 1;
		std::map<int, bool>::iterator it = graph[now].begin();
		for (; it != graph[now].end(); it++) //访问当前课程的下一个可学习课程
		{
			int x = it->first;
			dfs(x);
			if (f)
				break;
		}
		onpath[now] = 0;
		return;
	}
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) //能否访问到所有的图
	{
		graph.resize(numCourses + 1);				   //创建节点
		for (int i = 0; i < prerequisites.size(); i++) //添加边
		{
			// a的学习前提是学了b,即学了b可以学a
			int a = prerequisites[i][0];
			int b = prerequisites[i][1];
			graph[b].insert(pair<int, bool>(a, 1));
		}
		for (int i = 1; i <= numCourses; i++) //判断每个课程是否出现环
		{
			onpath.resize(numCourses + 1, 0);
			visit.resize(numCourses + 1, 0);
			dfs(i);
			if (f)
				break;
			visit.clear();
			onpath.clear();
		}
		return !f;
	}
};
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int n = 5; //共有n门课程
	vector<vector<int>> p = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
	Solution a;
	cout << a.canFinish(n, p);
	//学1课程必须先学0,学0课程前需要学1课程
	//如果成环,学不完所有的课程
	return 0;
}
