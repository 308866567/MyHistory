#include <iostream>
using namespace std;
const int N=1e5+2;
class l { //����ģ������
	public:
		int now;//���һ���ڵ�ĵ�ַ
		int s=-1;//����ַ
		int ne[N];//��ַ-��һ����ַ
		int p[N];
		int v[N];//��ַ-ֵ
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
			//�޸�a����һ���ڵ�
			ne[pc[a]]=ne[a];
		}
		//�����ַ
		void outa(int a) {
			for (int i = 10000; i > 0; i /= 10) {
				if (i > a)
					cout << "0";
			}
			if (a)//aΪ0��ʱ��
				cout << a;
		}
		//���������������
		void out() {
			int t=s;
			while(t!=-1)
			outa(t);
			cout<<" "<<v[t]<<" "<<ne[
			}
		}

};
int s,n;
bool used[N]= {}; //ֵ
int main() {
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	cin >> s >> n;
	l l1,l2;
	l1.s=s;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c; // ��ַ ��ֵ ��һ�����
		l1.add(a,b,c);
	}
	//����l1,�ظ����ֵ�ֵ�ŵ�l2ȥ
	int t=l1.s;
	while(t!=-1) {
		//û�����
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
