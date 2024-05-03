#include <iostream>
#include <algorithm>
using namespace std;
const long N=1e5+3;
long n,n0,n1;
//计算入住人数差,返回绝对值
long slove(long x) {
	double a=1.0*n0/x;
	double b=1.0*n1/(n-x);
	long long A=a;
	long long B=b;
//	cout<<a<<' '<<b<<' ';
	if(A!=a||B!=b||a==1||b==1) {
		return 1e8;
	} else
		return a-b>0?a-b:b-a;
}
//long rf() {
//	long l=1,r=n+1,mid;
//	while(l<r) {
//		mid=(l+r)2;//女生入住了mid间寝室
//		if() {//在右边
//			l=mid+1;
//		} else if() {//找到就向右
//			l=mid+1;
//		} else if() {//在左边
//			r=mid;
//		}
//	}
//	//l>=r
//}
long d[N];//分i间女生,两种性别每间寝室的人数差a-b
long ans=0;
//单调关系是?i增大,a>b时a减小,b增大,差的绝对值减小,向右二分
int main() {
//		freopen("C://Temp//in.txt","r",stdin);
	d[0]=1e7;
	cin>>n0>>n1>>n;
	for(int i=1; i<n; i++) {
		d[i]=slove(i);
//		cout<<d[i]<<'\n';
		if(d[i]<d[ans])
		ans=i;
	}
//	cout<<"\n";
	if(ans==0)
		cout<<"No Solution";
	else
		cout<<ans<<' '<<n-ans;
	return 0;
}
