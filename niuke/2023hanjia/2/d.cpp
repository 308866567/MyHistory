#include <iostream>
#include <algorithm>
using namespace std;
const long long maxx=2e6+10;
long long n;//n���ڵ�
long long f[maxx];//���ڵ��ǵ�1��
long long d[maxx];//���,���ڵ�Ϊ1
long long v[maxx];//ÿ������������
int main()
{
	d[0]=1;
	cin>>n;
	for(long long i=1;i<n;i++)
	{
		cin>>f[i];
		d[i]=d[f[i]-1]+1;
	}
	for(long long i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v,v+n);//��С����
	sort(d,d+n);
	long long sum=0;
	for(long long i=0;i<n;i++)
	{
		sum+=v[i]*d[i];
	}
	cout<<sum;
	return 0;
}
