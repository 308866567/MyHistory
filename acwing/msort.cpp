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
//
ll arr[N];
ll temp[N];
ll ans = 0;
void merge(ll b, ll mid, ll e, ll *a, ll *c)
{
	for (int i = b; i <= e; i++) //��������
	{
		c[i] = a[i];
	}
	ll i = b, j = mid + 1; //˫ָ��
	for (ll p = b; p <= e; p++) //ÿ��ȷ��һ��a[p]
	{
		if (i == mid + 1) //�������Ԫ������
		{
			a[p] = c[j++];
		}
		else if (j == e + 1)
		{
			a[p] = c[i++];
		}
		else if (c[i] <= c[j])
		{
			a[p] = c[i++];
		}
		else//��������Ԫ�ر�������С
		{
			a[p] = c[j++]; //��С����,�ȷ�С��
			ans += mid - i + 1;//���������䳤��
		}
	}
}
void msort(ll b, ll e, ll a[], ll c[]) //�鲢����
{
	if (b == e)
		return;
	ll mid = (b + e) / 2;
	msort(b, mid, a, c);
	msort(mid + 1, e, a, c); //�ݹ�������
	//���������� nums[l..mid] ���������� nums[mid+1..hi]
	//�ϲ�Ϊ�������� nums[l..hi]
	merge(b, mid, e, a, c);
}
int main()
{
	fre;
	fast;
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	msort(1, n, arr, temp);
	cout << ans;
	return 0;
}
