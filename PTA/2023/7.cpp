#include <iostream>
#include <algorithm>
using namespace std;
const long N=1e5+3;
long n,n0,n1;
//������ס������,���ؾ���ֵ
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
//		mid=(l+r)2;//Ů����ס��mid������
//		if() {//���ұ�
//			l=mid+1;
//		} else if() {//�ҵ�������
//			l=mid+1;
//		} else if() {//�����
//			r=mid;
//		}
//	}
//	//l>=r
//}
long d[N];//��i��Ů��,�����Ա�ÿ�����ҵ�������a-b
long ans=0;
//������ϵ��?i����,a>bʱa��С,b����,��ľ���ֵ��С,���Ҷ���
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
