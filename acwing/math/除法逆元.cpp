#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod; //�궨��һ��mod
//�������Ż�
ll quick_pow(ll a,ll b)
{
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
}

//��Ԫ���� ��ʽΪ (a/b)%mod=(a*b^(mod-2))%mod
ll inv(ll a,ll b)
{
	return (a*quick_pow(b,mod-2))%mod;
}

/***
ע�������Ԫ������ʹ�ã�a����������b������modΪ����
**/

int main()
{
	ll a,b;
	while(cin>>a>>b>>mod){
		cout<<inv(a,b)<<endl;
		//���(a/b)%mod����Ԫ
	}
	return 0;
}
