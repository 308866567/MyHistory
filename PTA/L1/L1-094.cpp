#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e3;
string s;
ll n;
string t;

void test() {
	cin >> s;
	cin >> t;
	cout << s.find_first_of(t);
}
int main() {
//	test();
//	return 0;
	cin >> s >> n;
	string a, b;
	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r >> a >> b;
		t = s.substr(l - 1, r - l + 1);
		s.erase(l - 1, r - l + 1 );
		//寻找插入位置
		string target = a + b;
		l = s.find(target);
		if (l == string::npos)
			l = s.size() ;   
		else
			l += a.size();
		s.insert(l, t);
	}
	cout << s << "\n";
	return 0;
}
