#include <iostream>
#include <deque>
using namespace std;
class game {
	public:
		deque <int>A;
		deque <int>B;
		int maxx=-1;//最高的层数
		int s=0;//个数
		//第一块
		game() {
			int t;
			cin>>t;
			A.push_front(t);
		}
		void push(int c) {
			if(c<A.front()) {
				A.push_front(c);
			} else if(B.empty()||c>B.front()) {
				B.push_front(c);
			} else { //更新成品
				int t=A.size();
				if(t>maxx)
					maxx=t;
				s++;
				A.clear();
				while(!B.empty()&&B.front()>c) {
					t=B.front();
					A.push_front(t);
					B.pop_front();
				}
				A.push_front(c);
			}
			return;
		}
		void end() {
			int t=A.size();
			if(t>maxx)
				maxx=t;
			if(t>0) s++;
			t=B.size();
			if(t>maxx)
				maxx=t;
			if(t>0) s++;

		}

};
int main() {
//	freopen("C://Temp//in.txt","r",stdin);
	int n;
	cin>>n;
	game x;
	int t;
	for(int i=1; i<n; i++) {
		cin>>t;
		x.push(t);
	}
	x.end();
	cout<<x.s<<' '<<x.maxx;
	return 0;
}
