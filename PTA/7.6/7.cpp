#include <iostream>
#include <deque>
#include <unordered_map>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
deque <int> s2;//存储数字
deque <char> s1;//符号,已经排好运算顺序
inline ll read(char &c, ll &x)
{
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}
inline void cal(char x)//操作符计算
{
	if(s2.size()<2) 
		return;
	ll b = s2.back();
	s2.pop_back();
	ll a = s2.back();
	s2.pop_back();
	if (x == '+')
	{
		s2.push_back(a + b);
	}
	else if (x == '-')
	{
		s2.push_back(a - b);
	}
	else  if (x == '*')
	{
		s2.push_back(a * b);
	}
	else  if (x == '/')
	{
		s2.push_back(a / b);
	}
	return ;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	char x;
	ll s = 0;
	while ((x = getchar()) != EOF)
	{
		if (x >= '0' && x <= '9')
		{
			s2.push_back(read(x, s));
			s = 0;
		}
		if (s1.empty())//为空
		{
			s1.push_back(x);
			continue;
		}
		
		//处理运算符
		//优先级高直接添加,左括号,
		if ( x == '(' || x == '*' || x == '/')
			s1.push_back(x);
		else if (x == ')') //右括号,弹出操作符进行计算直到遇到'('
		{
			while (!s1.empty())
			{
				x = s1.back();
				s1.pop_back();
				if (x == '(')
					break;
				cal(x);
			}
		}
		//和顶比较,优先级大的话先算
		//如果顶是*/,弹出并计算,直到碰到+-
		//想放入+-,*/先算
		else //if ((top == '*' || top == '/') && (x == '+' || x == '-'))
		{
			char t = x;
			while (!s1.empty())
			{
				x = s1.back();
				if (x != '*' && x != '/')
					break;
				s1.pop_back();
				cal(x);
			}
			s1.push_back(t);
		}
	}
	while (!s1.empty())
	{
		x = s1.back();
		s1.pop_back();
		cal(x);
	}
	cout << s2.front();
	return 0;
}
