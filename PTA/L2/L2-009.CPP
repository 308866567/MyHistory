#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define rrep(i, start, end) for (ll i = start; i >= end; i--)
#define inf 0x3f3f3f3f
ll n;

struct node{
	ll sum=0;//单位:分
	ll s=0;//红包个数
	ll i;//个人编号
	bool operator<(const node &t){
		if(sum!=t.sum)
			return sum>t.sum;
		if(s!=t.s){
			return s>t.s;
		}
		return i<t.i;
	}
	void out(){
		cout<<i<<' ';
		printf("%.2lf\n",1.0*sum/100);
	}
}man[N];


void slove()
{
	cin >> n;
//	string x=to_string(n);
	rep(i,1,n){
		man[i].i=i;
		ll k;
		cin>>k;
		ll ni,p;
		ll ss=0;
		rep(j,1,k){
			cin>>ni>>p;
			ss+=p;
			man[ni].sum+=p;
			man[ni].s++;
		}
		man[i].sum-=ss;
	}	
	sort(man+1,man+1+n);
	rep(i,1,n){
		man[i].out();
	}
	return;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\30886\\Desktop\\in.txt","r",stdin);
#endif
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		slove();
	}
	return 0;
}


//快读
inline int read() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x * f;
}


