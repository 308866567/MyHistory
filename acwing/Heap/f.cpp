#include <iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const long long N = 1e6 + 1;
class Heap//Ѱ����λ��
{
	//	������������ʱ���󶥶ѱ�С���Ѷ�һ��Ԫ�أ���λ�����Ǵ󶥶ѶѶ���
public:
	priority_queue <ll, vector<ll>, less<ll>> minn; //����λ��С��,��
	priority_queue <ll, vector<ll>,greater<ll>> maxx; //����λ�����,С��
	int s1 = 0, s2 = 0;
	void makebalance()
	{
		if (s1 > s2 + 1)
		{
			maxx.push(minn.top());
			s2++;
			s1--;
			minn.pop();
		}
		else if (s2 > s1 )
		{
			minn.push(maxx.top());
			s2--;
			s1++;
			maxx.pop();
		}
	}
	void push(ll x)
	{
		if (s1 == 0 && s2 == 0)
		{
			minn.push(x);//��ΪĬ�����minn
			s1++;
			return;
		}
		ll t = out();
		if (x <= t)
		{
			minn.push(x);
			s1++;
		}
		else
		{
			maxx.push(x);
			s2++;
		}
		makebalance();
	}
	double out()
	{
		if (s1 == 0) return 0;
		if (s1 == s2)
			return (1.0 * maxx.top() / 2 + 1.0 * minn.top() / 2) ;
		else
			return minn.top();
	}
};
int main()
{
		freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	//ios::sync_with_stdio(0);
	//  cin.tie(0);
	// cout.tie(0);
	ll n, m;
	ll a, b, c;
	Heap h;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		h.push(a);
	}
	cin >> m;
	string t;
	for (int i = 1; i <= m; i++)
	{
		cin >> t;
		if (t == "add")
		{
			cin >> a;
			h.push(a);
		}
		else
		{
			cout<<h.minn.top()<<"\n";
		}
	}
	return 0;
}
