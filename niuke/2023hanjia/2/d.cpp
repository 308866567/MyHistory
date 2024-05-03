#include <iostream>
#include <algorithm>
using namespace std;
const long long maxx=2e6+10;
long long n;//n个节点
long long f[maxx];//根节点是第1个
long long d[maxx];//深度,根节点为1
long long v[maxx];//每个能量球能量
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
	sort(v,v+n);//从小到大
	sort(d,d+n);
	long long sum=0;
	for(long long i=0;i<n;i++)
	{
		sum+=v[i]*d[i];
	}
	cout<<sum;
	return 0;
}
