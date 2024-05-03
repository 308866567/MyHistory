#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e5+87;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
ll n, m;//m����ڼ��������Ԫ��
class heap
{
#define ls u<<1
#define rs ((u<<1)|1)
public:
	ll h[N], ph[N], hp[N], cnt=0;
	//ph��point->heap�����Ի�õڼ��������Ԫ�������ڶѵ��Ǹ�λ��
	//hp(heap->point)���Ի���ڶѵĵ�n��Ԫ�ش���ǵڼ��������Ԫ��
	//h ��λ��-ֵ
	//hp ��λ��-�ڼ�������
	//ph �ڼ�������-��λ��
	void heap_swap(ll a, ll b)
	{
		swap(ph[hp[a]], ph[hp[b]]);
		swap(hp[a], hp[b]);
		swap(h[a], h[b]);//�ڵ�ֵ����
	}
	void down(ll u)//�³�u
	{
		
		ll t = u;//t��Ϊ3�������Сֵ
		if (ls <= cnt && h[ls] < h[t]) t = ls;
		if (rs <= cnt && h[rs] < h[t]) t = rs;
		if (u != t)//������min,�³�
		{
			heap_swap(u, t);
			down(t);
		}
	}
	void up(ll u)//��Ԫ�ض����ڶ�β,��������
	{
		while (u / 2 && h[u] < h[u / 2])//С�ڸ��ڵ�ͽ���
		{
			heap_swap(u, u / 2);
			u >>= 1;
		}
	}
	void slove()
	{
		string op;
		ll k, x;
		while (n--)
		{
			cin >> op;
			if (op == "I")//����
			{
				cin >> x;
				cnt++, m++;
				ph[m] = cnt;
				hp[cnt] = m;
				h[cnt] = x;
				up(cnt);
			}
			else if (op == "PM")
			{
				cout << h[1]<<"\n";
			}
			else if (op == "DM")
			{
				heap_swap(1, cnt);
				cnt--;
				down(1);
			}
			else if (op == "D")
			{
				cin >> k;
				k = ph[k];
				heap_swap(k, cnt);//ĩβԪ�ش���k��λ��
				cnt--;
				down(k);
				up(k);
			}
			else
			{
				cin >> k >> x;
				k = ph[k];
				h[k] = x;
				down(k);
				up(k);
			}
		}
		return;
	}
};
int main()
{
	//	fre;
	fast;
	cin >> n ;
	heap H;
	H.slove();
	return 0;
}
