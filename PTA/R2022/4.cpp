#include <iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
const ll N = 9999; //1��9999��
using namespace std;
//����
vector<int> r;
int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //ÿ���·ݵ�����,��������
//%7
//������������Ͷ�Ӽ���
int a, b;

//Ѱ������
void f(int x)
{
	for (int i = 1; i <= x; i++)
	{
		if (i % 400 == 0)
		{
			r.push_back(i);
		}
		else if (i % 4 == 0 && i % 100 != 0)
		{
			r.push_back(i);
		}
	}
}
bool f1(int a)
{
	if (a % 400 == 0)
	{
		return 1;
	}
	else if (a % 4 == 0 && a % 100 != 0)
	{
		return 1;
	}
	return 0;
}
ll slove(int a, int b)
{
	ll sum = 0;
	//��
	sum += (a - 1) * 365;
	ll t =	upper_bound(r.begin(), r.end(), a) - r.begin() - 1;
	//t������,������ǰ��
	sum += t;
	if(f1(a)&&b<=2)sum--;
//cout<<t;
	for (int i = 1; i < b; i++)
	{
		sum += m[i];
	}
	//��
//	cout << sum % 7;
	return sum % 7;
}

int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	//a��,b��
	int a = 2022, b = 12;
	cin >> a >> b;
	r.push_back(0);
	f(9999);
	ll s = slove(a, b); //=1,+1��ʾ���ڼ�
//	cout << s << "\n";
	cout << " Sun Mon Tue Wed Thu Fri Sat\n";
	int j = s + 2;
	if (s == 6)
	{
		s = -1, j = 1;
	}
	for (int i = 0; i < s+1; i++)
	{
		printf("    ");
	}
	s = 1;
if(f1(a)) m[2]++;
	while (s <= m[b])
	{
		printf("%4lld", s++);
		j++;
		if (j > 7)
		{
			cout << "\n";
			j = 1;
		}
	}
	if (j != 1)
		cout << "\n";
	return 0;
}
