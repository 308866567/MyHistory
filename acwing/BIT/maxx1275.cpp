#include <iostream>
typedef long long ll;
using namespace std;
const ll N = 3e5 + 5;
ll m, p;//�����2e5����
ll n = 0;//��ǰ���еĸ���
class BIT//��״����ά�����ֵ
{
	public:
		ll t[N] = {0}; //�洢�������ֵ
		//t[i]��ʾ����[i-low+1,i]�����ֵ
		ll *a;//����
		inline lowbit(ll x){
			return x&(-x);
		}
		void build()
		{

		}
		//�����޸�
		void update()
		{

		}
		//���������ֵ,�����ѯ
		ll query()
		{
			return 1;
		}
};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> p;
	char t1;
	ll t2;
	ll a = 0;
	BIT T;
//	T.build(1,1,m);
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		if (t1 == 'A')//��Ӳ���
		{
			t2 = (t2  + a) % p;
			//���t2��ĩβ
			n++;
//			T.update(n, n, t2, 1, 1, m);
		}
		else//��ѯ����
		{
			//			cout<<n-t2+1<<" "<<n<<":";
//			a = T.query(n - t2 + 1, n, 1, 1, m);
			cout << a << "\n";
		}
		//7029
	}
	return 0;
}
