#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class stu
{
public:
    int a;
    int b;
    char c;
    string d;
    stu(int x)
    {
        a = x;
    }
    bool operator<(const stu &x) const
    {
        return a > x.a;
    }
};
typedef pair<int, int> PII;
struct cmp
{
    bool operator()(const PII &a, const PII &b)
    {
        return a.second > b.second;
    }
};

// 升序队列
// priority_queue<int, vector<int>, greater<int>> q;
// 降序队列
// priority_queue<int, vector<int>, less<int>> q;
// sort(a+1,a+n+1,greater<int>()); //降序
// sort(a+1,a+n+1,less<int>()); //升序，注意尖括号内写的是排序的数组类型
int main()
{
    priority_queue<PII, vector<PII>, cmp> q;
    // stu a(1);
    // stu b(2);
    // q.push(a);
    // q.push(b);
    // cout<<q.top().a;
    PII a = {1, 22};
    PII b = {1, 3};
    q.push(a);
    q.push(b);
    q.push(PII(1, 25));
    // bool f = a < b;
    cout << q.top().second;
    return 0;
}