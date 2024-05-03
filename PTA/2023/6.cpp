#include <iostream>
#include <string>
using namespace std;
class tool {
	public:
		string arr;//字符串位置从 1 开始编号
		int n;
		tool() {
			cin>>arr;
			cin>>n;
		}
		void in() {
			for(int i=0; i<n; i++) {
				jian();
			}
		}
		void jian() {
			int a,b;
			string ta,tb;
			cin>>a>>b;
			cin>>ta;
			cin>>tb;
			string p=ta+tb;
			//删除a-b，放到剪贴板
			string temp=arr.substr(a-1,b-a+1);
			arr.erase(a-1,b-a+1);
//			cout<<temp<<"\n";
			//寻找插入位置，ta+tb
			int start=arr.find(p);//返回起始下标,没找到则大于arr.size()
//				cout<<start<<"\n";
			if(start>arr.size()||start<0) {
				start=arr.size();
			} else
				start+=ta.size();
		
//			cout<<start<<"\n";
			arr.insert(start,temp);
//				cout<<""<<arr<<"\n\n";
//			cout<<arr<<"\n";
		}
};
int main() {
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
//	cout << "No Solution";
	tool x;
	x.in();
	cout<<x.arr;
	return 0;
}
