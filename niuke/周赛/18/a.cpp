#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>



unordered_map<ll, unordered_map<ll, ll>> g;
//
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	ll n, k;
	string a;
	char ch;
	ch = getchar();
	while (ch >= '0' && ch <= '9') {
		a += ch;
		ch = getchar();
	}
	cin >> k;
	ll len = a.size();
	
	if(a[0]=='0'&&len==1){
		cout<<0;return 0;
	}
	int i=k-1;
	while(a[i]=='0'){
		i--;
	}
	for (; i >= 0; i--) {
		
		cout << a[i];
	}
	for (int i = k; i < len; i++) {
		cout << a[i];
	}
	return 0;
}

