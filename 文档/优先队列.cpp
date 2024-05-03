#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 定义：priority_queue<Type, Container, Functional>
// Type 就是数据类型，
// Container 就是容器类型（Container必须是用数组实现的容器，
// 比如vector,deque等等，但不能用 list。STL里面默认用的是vector），
// Functional 就是比较的方式。

//升序队列       从小到大
priority_queue <int,vector<int>,greater<int> > q;
//降序队列       从大到小
priority_queue <int,vector<int>,less<int> >q;
//greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。
// 其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）

// top 访问队头元素
// empty 队列是否为空
// size 返回队列内元素个数
// push 插入元素到队尾 (并排序)
// emplace 原地构造一个元素并插入队列
// pop 弹出队头元素
// swap 交换内容