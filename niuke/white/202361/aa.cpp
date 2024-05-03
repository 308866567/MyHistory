#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char x;
	cin>>x;
	int num=0;
	int n;
	cin>>n;
	if(x=='*'||x=='='||x==','){
		cout<<(1+n)*n/2;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				string ii=to_string(i);
				int leni=ii.length();
				for(int i=0;i<leni;i++){
					//					cout<<s[i]<<" ";
					if(ii[i]==x){
						num++;
					}
				}
				string jj=to_string(j);
				int lenj=jj.length();
				for(int i=0;i<lenj;i++){
					//					cout<<s[i]<<" ";
					if(jj[i]==x){
						num++;
					}
				}
				string s=to_string(i*j);
				//				cout<<s<<endl;
				int lens=s.length();
				for(int i=0;i<lens;i++){
					//					cout<<s[i]<<" ";
					if(s[i]==x){
						num++;
					}
				}
				//				cout<<endl;
				//				cout<<i<<" "<<j<<" "<<num<<endl;
			}
		}
		cout<<num;
	}
}

