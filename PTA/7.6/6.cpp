#include <iostream>
#include <vector>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
int n;
vector<int> ans;
bool used[N] = {0, 0};
int main()
{
//		freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	int n;
	cin >> n;
	//�������
	//һ���������ʵĻ�,���޷���1���ֿ�
	
	//��������Ĵη�
	//�η���ѯ�ʵĻ�,�޷�������^1���ֿ�(�ҹ���)
	//����4,�޷�ͨ����2�ж�,2��4���ж���һ����
	
	
	//��������(ָ������,����>=2��)������ת����p1^k*p2^k����ʽ��
	//��m��������ʱ,m����������(1,m,x,m/x);(xΪ����)
	
	//m������ʱ,����Ϊ(1,m)
	//m^k�������Ĵη�ʱ,����Ϊ(1,m^k,m)
	
	//���� a ������ b ��Ȼ���� a��b����������ѯ�ʡ�
	//����6=2^1*3^1,ѯ��6�Ľ����������2����3�õ�,����6����ѯ��
	//��Ϊ����һ�������������Ա�ʾΪ��������Ĵη���˵���ʽ��
	//�ⱻ��Ϊ�������ֽ���������ֽ⡣
	for (int i = 2; i <= n; i++)
	{
		if (used[i])//��������
			continue;
		for (int j = i; j <= n; j *= i)
		{
			ans.emplace_back(j);//��������Ĵη�
		}
		//�õ�ǰ��ӵ�����ɸȥ�䱶��
		for (int j = i + i; j <= n; j += i) //����ɸ����
		{
			used[j] = 1;
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
