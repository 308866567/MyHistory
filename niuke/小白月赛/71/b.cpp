#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	string arr;
	cin>>arr;
	string t[4]= {"ove","lve","loe","lov",};
	for(int i=0; i<4; i++) {
		if(arr.find(t[i])<arr.size()) {
			cout<<"YES";
			return 0;
		}
	}	cout<<"NO";
	return 0;
}
