#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
	vector<bool> visit;
	vector<bool> onpath;		  //��¼·��
	vector<map<int, bool>> graph; //�ڽӱ�
	bool f = 0;					  //�Ƿ���ֻ�
	void dfs(int now)			  // now��ʾ�ڼ��ſγ�
	{
		if (onpath[now] ) //���ֻ�
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
		for (; it != graph[now].end(); it++) //���ʵ�ǰ�γ̵���һ����ѧϰ�γ�
		{
			int x = it->first;
			dfs(x);
			if (f)
				break;
		}
		onpath[now] = 0;
		return;
	}
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) //�ܷ���ʵ����е�ͼ
	{
		graph.resize(numCourses + 1);				   //�����ڵ�
		for (int i = 0; i < prerequisites.size(); i++) //��ӱ�
		{
			// a��ѧϰǰ����ѧ��b,��ѧ��b����ѧa
			int a = prerequisites[i][0];
			int b = prerequisites[i][1];
			graph[b].insert(pair<int, bool>(a, 1));
		}
		for (int i = 1; i <= numCourses; i++) //�ж�ÿ���γ��Ƿ���ֻ�
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
	int n = 5; //����n�ſγ�
	vector<vector<int>> p = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
	Solution a;
	cout << a.canFinish(n, p);
	//ѧ1�γ̱�����ѧ0,ѧ0�γ�ǰ��Ҫѧ1�γ�
	//����ɻ�,ѧ�������еĿγ�
	return 0;
}
