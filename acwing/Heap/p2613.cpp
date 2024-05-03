#include <iostream>
typedef long long ll;
const ll mod = 19260817;
const ll N=2e4+10;
using namespace std;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	else
	{
		ll ans = exgcd(b, a % b, x, y);
		ll t = x;
		x = y;
		y = t - a / b * y;
		return ans;
	}
}
ll slove(ll a, ll c)
{
	ll x, y;
	ll b = 19260817; //模数
	//ax+by=c求解
	ll d = exgcd(a, b, x, y);
	if (c % d != 0) return -1;
	a /= d;
	b /= d;
	c /= d;
	exgcd(a, b, x, y);
	x *= c;
	y *= c;
	ll x1 = x > 0 && x % b != 0 ? x % b : x % b + b;
	return x1;
}

char in[N];
ll cnt=0;
void nc()
{
	fread(in, sizeof(char), N, stdin);
}

ll read()
{
	ll s=0;
	int f=1;
	while((in[cnt]<'0'||in[cnt]>'9')&&in[cnt]!='-')
	{
		cnt++;
	}
	if(in[cnt]=='-'){
		cnt++;
		f=-1;
	}
	while(in[cnt]>='0'&&in[cnt]<='9')
	{
		s=s*10+in[cnt]-'0';
		s%=mod;
		cnt++;
	}
	return s*f;
}

int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	nc();
	ll a=read(), b=read();
//	cin >> a >> b;
	//bx+mod*y=a
	ll t =	slove(b, a);
	if (t == -1)
		cout << "Angry!";
	else
		cout << t;
	return 0;
}
