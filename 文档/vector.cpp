#include <iostream>
#include <stack>  //c的栈，后进先出
#include <queue>  //c的队列，先进先出
#include <vector> //容器
#include <algorithm>
using namespace std;
int aa(vector<int>&a, vector<int>&b)
{
	vector<int> b(10, 1);	//定义了10个整型元素的向量,且给出每个元素的初值为1
	vector<int> a(b);	//用b向量来创建a向量，整体复制性赋值
	vector<int> aaa(b.begin(), b.begin() + 3);	//定义了a值为b中第0个到第2个（共3个）元素
	int i = 1;
	int c[10] = {0};
	a[i];								   //返回a的第i个元素，当且仅当a[i]存在
	a.insert(a.begin() + 1, 5);			   //在a的第1个元素（从第0个算起）的位置插入数值5
	a.clear();							   //清空a中的元素
	a.empty();							   //判断a是否为空，空则返回ture,不空则返回false
	a.pop_back();						   //删除a向量的最后一个元素
	a.erase(a.begin() + 1, a.begin() + 3); //删除a中第1个（从第0个算起）到第2个元素
	a.push_back(5);						   //在a的最后一个向量后插入一个元素
	a.insert(a.begin() + 1, 5);			   //在a的第1个元素（从第0个算起）的位置插入数值5
	a.insert(a.begin() + 1, 3, 5);		   //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
	// c为数组，在a的第1个元素（从第0个算起）的位置插入c的第3个元素到第5个元素
	a.insert(a.begin() + 1, c + 3, c + 6);
	a.size();		 //返回a中元素的个数；
	a.resize(10, i); //将a的现有元素个数调至10个，多则删，少则补，其值为i
	a.reserve(100);	 //将a的容量（capacity）扩充至100
	a.swap(b);		 // b为向量，将a中的元素和b中的元素进行整体性交换
	reverse(a.begin(), a.end());	//对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列
	return 0;
}
int cc(void)
{
	stack<int> name1; //声明存储int类型的栈，后进先出
	int a = 1;
	name1.push(a); //栈顶放入
	name1.pop();   //移除栈顶
	//
	queue<int> name2;
	name2.push(a); //末尾放入
	name2.pop();   //移除开头
	return 0;
}
int main(void)
{
	return 0;
}
