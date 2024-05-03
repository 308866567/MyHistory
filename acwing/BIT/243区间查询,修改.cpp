#include <iostream>
using namespace std;

class BIT3
{
	public:
		typedef long long ll;
		const static ll N = 1e2 + 1;
		ll n, m;
		ll a[N] = {0}; //ԭ����
		ll td[N] = {0}; //a�Ĳ������
		//a[i]=d1+d2+..+dia 
		ll tdi[N] = {0}; //�������*i
		//��Ϊ�����s[x]=(x+1)*(d1+..dx)-(x*dx+...+1*d1) 
		void build(){
			//o(n)������״����
			//��״����t[i]��ֵΪԭ����ǰ׺��s[i]-s[i-lowbit[i]]
			//��a[i-lowbit[i]+1,i]�������=s[i]-s[i-lowbit[i]]
			//��������s[i]=a[i]
			for (int i = 1; i <= n; i++)
			{
				//�ӽڵ��ʼֵΪԭ����
				//tdΪԭ����Ĳ������
				//��״����ײ�td[i]=a[i]-a[i-1]
				ll j = a[i] - a[i - 1];//���ֵ 
				td[i] += j;
				tdi[i] += j * i;
				//�����ӽڵ���¸��ڵ�
				j = i + lowbit(i);
				if (j <= n)
				{
					//+=����Ϊһ�����ڵ���ж���ӽڵ�
					td[j] += td[i]; 
					tdi[j] += tdi[i];
				}
			}
		}
		void slove()
		{
			cin >> n >> m;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
				//��������
//				update(i, a[i] - a[i - 1], td);
//				update(i, (a[i] - a[i - 1])*i, tdi);
			}
			build();
			char a;
			ll l, r, d;
			while (m--)
			{
				cin >> a;
				if (a == 'Q')//�����ѯ
				{
					cin >> l >> r;
					ll d = (sum(r) - sum(l - 1));
					cout << d << "\n";
				}
				else//�����޸�
				{
					cin >> l >> r >> d;
					add(l, r, d);
				}
			}
		}
		inline ll lowbit(ll x)
		{
			return x & (-x);
		}
		//������²������
		void update(ll x, ll k, ll *t)
		{
			for (int i = x; i <= n; i += lowbit(i))
			{
				t[i] += k;
			}
		}
		//����a[x],�����ѯ
		ll query(ll x, ll *t)
		{
			ll res = 0;
			for (int i = x; i > 0; i -= lowbit(i))
			{
				res += t[i];
			}
			return res;
		}
		//�����޸�
		void add(ll l, ll r, ll d)
		{
			update(l, d, td);
			update(r + 1, -d, td);
			update(l, l * d, tdi);
			update(r + 1, (r + 1) * -d, tdi);
		}
		//��ѯԭ����a[1,i]��ǰ׺��
		ll sum(ll x)
		{
			//s[x]=(x+1)*(d1+..dx)-(x*dx+...+1*d1)
			return  query(x, td) * (x + 1) - query(x, tdi) ;
		}
};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	BIT3 A;
	A.slove();
	return 0;
}
