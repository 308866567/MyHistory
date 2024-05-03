#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 10;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//��������������(������ô󶥶ѣ��������С����)
ll n, m;
class heap
{
public:
		ll a[N];
		ll R;//�ѵ��ұ߽�
		void slove()
		{
			R = n;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			//�ӵ�һ����Ҷ�ڵ㿪ʼ�����ҵ��󣬴��µ��ϴ���ÿ���ڵ�
			for (int i = n >> 1; i >= 1; i--)
			{
				down(i);
			}
			while (m--)
			{
				cout << a[1] << ' ';
				swap(a[1], a[R]);
				R--;
				down(1);
			}
		}
		void down(ll u)
		{
			ll t = u;
			ll l = u << 1, r = u << 1 | 1;
			//�������,������ӱ�tС,����
			if (l <= R && a[l] < a[u])
				t = l;
			//���Ҷ���,���Ҷ��ӱ�tС,����
			if (r <= R && a[r] < a[t])
				t = r;
			//����������㲻����С��
			if (u != t)
			{
				swap(a[u], a[t]);
				down(t);
			}
		}
};
int main()
{
//	fre;
	fast;
	cin >> n >> m;
	heap H;
	H.slove();
	return 0;
}
