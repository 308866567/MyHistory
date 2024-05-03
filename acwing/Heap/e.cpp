#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const long long N = 1e5+10;
unordered_map<ll, unordered_map<ll, ll>> g;
#define fre freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//��Ŀ��λ��ȡfloor(len/2)+1
//������λ��x������len/2��>=x
ll arr[N];//ԭ����
ll sum[N];
ll temp[N];
ll n;
ll s = 0;
void merge(ll b, ll e, ll *nums, ll *temp)
{
	for (int i = b; i <= e; i++)
	{
		temp[i] = nums[i];
	}
	ll l = b, mid = (b + e) >> 1, r = mid + 1;
	for (int p = b; p <= e; p++)
	{
		if (l > mid)
		{
			nums[p] = temp[r++];
		}
		else if (r > e)
		{
			nums[p] = temp[l++];
		}
		else if (temp[l] > temp[r])
		{
			nums[p] = temp[l++];
		}
		else//�����λ��*r>=*(l-1)
		{
			nums[p] = temp[r++];
			s += mid - l + 1;
		}
	}
}
void msort(ll b, ll e, ll *nums)
{
	if (b == e) return ;
	ll mid = (b + e) >> 1;
	msort(b, mid, nums);
	msort(mid + 1, e, nums);
	merge(b, e, nums, temp);
}
ll aim ;
bool check(ll x)//x����λ����Ҫ������len/2��>=x
{
	//�����ж��ٸ����䣬������λ��>=x
	//����ͨ������������жϣ������>=len*x�Ļ���������λ���϶�>=x
	//ͨ����ɢ�����������
	//���������ǰ׺������
	//sum[r]-sum[l-1]>=0�ȼ�sum[r]>=sum[l-1](r>l-1)
	//������Ը���
	sum[0]=0;
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] >= x)
			sum[i] = 1;
		else
			sum[i] = -1;
		sum[i] += sum[i - 1];
		if(sum[i]>=0) s++;
	}
	msort(1, n, sum);
//	cout<<x<<"-"<<s<<"\n";
	if (s >= aim)
	{
		return 1;
	}
	else return 0;
}
int main()
{
//	fre;
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	aim = (1LL + n) * n / 2;//�������
	aim=(aim + 1) / 2;
	//����ö����λ������λ��x
	ll l = 1, r = 1e9+10, mid;
	while (l < r) // �Ҳ�
	{
		mid = (l + r) >> 1;
		if (check(mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	cout << l-1;
	return 0;
}
