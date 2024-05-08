#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

ll n, m, k;
ll cal(ll mid){
	//成mid个t团
	ll a = n, b = m, t = k;
	//奇数团变偶数团
	if (k & 1) {
		a -= mid;
		t--;
	}
	t=t*mid/2;//需要t个2
	//先分配男生
	if(t>=a/2){
		t-=a/2;
		a%=2;
	}
	else {
		t=0;
		a-=t*2;
	}
	//分配女生
	if(t>0)
		b-=t;
	return b+a;
}

bool check(ll mid) {
	//能否分成mid个t团
	ll a = n, b = m, t = k;
	//奇数团变偶数团
	if (k & 1) {
		a -= mid;
		if (a < 0) 
			return 0;
		t--;
	}
	//男生变女生
	b += a / 2;
	ll sum = b * 2;//总价值
	if (sum >= mid*t)
		return 1;
	else
		return 0;
}
ll slove() {
	ll l = 0, r = n + m+1, mid;
	//二分求最多成团数
	while (l < r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}
ll slove2(){
	ll a = n, b = m, t = k;
	if(k&1){
		
	}	
	else
	{
		t/=2;//每组t个2钱
	}
	return 0;
}
int main() {
//	freopen("E:\\in.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		if(k==1) 
			cout<<m;
		else if(k==2)
			cout<<n%2;
		else
			cout<<cal(slove()-1);
		cout<<"\n";
	}
	return 0;
}
