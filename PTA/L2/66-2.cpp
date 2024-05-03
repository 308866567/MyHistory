#include <iostream>
using namespace std;
const int N=1e5+2;
class l { //数组模拟链表
	public:
		int now;//最后一个节点的地址
		int s=-1;//起点地址
		int ne[N];//地址-下一个地址
		int p[N];
		int v[N];//地址-值
		void add(int a,int b,int c) {
			if(s==-1) {
				s=a;
				now=a;
			}
			v[a]=b;
			ne[a]=c;
			p[c]=a;
			now=a;
		}
		void insert(int a,int b) {
			if(s==-1) {
				s=a;
				now=a;
			}
			ne[now]=a;
			v[a]=b;
			now=a;
		}
		void del(int a) {
			//修改a的上一个节点
			ne[pc[a]]=ne[a];
		}
		//输出地址
		void outa(int a) {
			for (int i = 10000; i > 0; i /= 10) {
				if (i > a)
					cout << "0";
			}
			if (a)//a为0的时候
				cout << a;
		}
		//正向输出整个链表
		void out() {
			int t=s;
			while(t!=-1)
			outa(t);
			cout<<" "<<v[t]<<" "<<ne[
			}
		}

};
int s,n;
bool used[N]= {}; //值
int main() {
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	cin >> s >> n;
	l l1,l2;
	l1.s=s;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c; // 地址 键值 下一个结点
		l1.add(a,b,c);
	}
	//遍历l1,重复出现的值放到l2去
	int t=l1.s;
	while(t!=-1) {
		//没输出过
		if(!used[l1.v[t]]) {
			used[l1.v[t]]=1;
			t=l1.ne[t];
		} else {
			l1.del(a);
			l2.insert(a);
		}
	}
	return 0;
}
