#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 1;
ll n, m;
ll a[N];
class segmentTree
{
public:
	ll t[4 * N] = {0}; //�洢�����
	ll *a;//����
	ll mark[4 * N] = {0};
	
	//���������±�
	inline ll ls(ll p)
	{
		return p << 1;//*2
	}
	
	//�����Һ����±�
	inline ll rs(ll p)
	{
		return p << 1 | 1;//*2+1
	}
	
	//����ʱ����ά������,���������
	void push_up(ll p)
	{
		t[p] = t[ls(p)] + t[rs(p)];//���Һ��ӵĺ�
	}
	
	//�ݹ�ʱ����ά�����,���ڵ㲻�ø���,��Ϊ���ڵ��Ѿ����¹���
	//��ѯʱ�����mark
	void push_down(ll p, ll l, ll r)
	{
		//�����ǰ�ڵ�������,��Ҷ�ӽڵ����
		if (mark[p] == 0) //���Ϊ0
			return ;
		ll mid = (l + r) >> 1;
		//			cout<<mark[p] * (mid - l + 1)<<" "<<mark[p] * (r - mid)<<" "<<"\n";
		t[ls(p)] += mark[p] * (mid - l + 1);//����仯,��ĸ���*�仯ֵ
		t[rs(p)] += mark[p] * (r - mid);
		mark[ls(p)] += mark[p];//Ҷ�ӽڵ���ϱ仯ֵ
		mark[rs(p)] += mark[p];
		mark[p] = 0;
	}
	
	
	segmentTree(ll *x)
	{
		a = x;
	}
	///�ݹ齨��,���ҷ��ʵ����ڵ�
	void build(ll p = 1, ll l = 1, ll r = n)
	{
		//p�ǵ�ǰ���ڵ����ڵ����,[l,r]����������
		if (l == r) t[p] = a[l];
		else
		{
			ll mid = (l + r) >> 1;
			build(ls(p), l, mid);
			build(rs(p), mid + 1, r);
			push_up(p);
		}
	}
	//����[tl,tr]ÿ���㶼����k
	void update( ll tl, ll tr, ll k, ll p = 1, ll l = 1, ll r = n)
	{
		
		//�����ǰ�ڵ�����������[tl,tr]��,ֱ���޸�
		if (l >= tl && r <= tr)
		{
			mark[p] += k;
			t[p] += k * (r - l + 1);
			return ;
		}
		push_down(p, l, r);
		ll mid = (l + r) >> 1;
		//[l,mid]��[mid+1,r]��������
		//mid��[tl,tr]��ʱ
		if (tl <= mid) //��벿���п��ܸ���Щ,����=��
			update(tl, tr, k, ls(p), l, mid );
		if (tr > mid)
			update(tl, tr, k, rs(p), mid + 1, r );
		push_up(p);
		//				out();
		//cout<<"\n";
		return;
	}
	
	//�����ѯ
	//pΪ��ǰ���ڽڵ����,����õ�ֵ
	ll query( ll tl, ll tr, ll p = 1, ll l = 1, ll r = n)
	{
		ll res = 0;
		//�����ǰ�ڵ�����������[tl,tr]��,ֱ�ӷ���
		if (l >= tl && r <= tr)
		{
			return t[p];
		}
		push_down(p, l, r);
		//			push_up(p);
		ll mid = (l + r) >> 1;
		//���[l,mid]��[tl,tr]���ཻ
		//��벿�������Ŀ��������
		if (tl <= mid)//��벿���п��ܸ���Щ,����=��
			res += query(tl, tr, ls(p), l, mid );
		//���[mid+1,r]��[tl,tr]���ཻ
		//�Ұ벿�������Ŀ��������
		if (tr > mid)
			res += query(tl, tr, rs(p), mid + 1, r);
		
		return res;
	}
	void out()
	{
		for (int i = 1; i <= 2 * n; i++)
		{
			cout << t[i] << ' ';
		}
		cout << "\n";
	}
};
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	segmentTree A(a);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	A.build();
	ll x;
	ll t;
	ll tl, tr, k;
	while (m--)
	{
		cin >> t ;
		switch (t)
		{
			case 1://����k
			//				x = A.query(1, n);
			//				cout << "old:" << x << "\n";
			cin >> tl >> tr >> k;
			A.update(tl, tr, k);
			//				x = A.query(1, n);
			//				cout << "new:" << x << "\n\n";
			break;
			case 2:	//��ѯ
			cin >> tl >> tr;
			x = A.query(tl, tr) ;
			cout <<	x << "\n";
			break;
		}
	}
	return 0;
}
