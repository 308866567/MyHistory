#include <iostream>
#include <deque>
#include <unordered_map>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
deque <int> s2;//�洢����
deque <char> s1;//����,�Ѿ��ź�����˳��
inline ll read(char &c, ll &x)
{
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}
inline void cal(char x)//����������
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
		if (s1.empty())//Ϊ��
		{
			s1.push_back(x);
			continue;
		}
		
		//���������
		//���ȼ���ֱ�����,������,
		if ( x == '(' || x == '*' || x == '/')
			s1.push_back(x);
		else if (x == ')') //������,�������������м���ֱ������'('
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
		//�Ͷ��Ƚ�,���ȼ���Ļ�����
		//�������*/,����������,ֱ������+-
		//�����+-,*/����
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
