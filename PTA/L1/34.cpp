#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class matrix
{
		int sr;
		int sc;
		vector<vector<int> > g;
		matrix(int a, int b)
		{
			sr = a;
			sc = b;
			g.resize(sr);
			int t;
			for(int i=0;i<sr;i++){
				for(int j=0;j<sc;j++){
					cin>>t;
					g[i].push_back(t);
				}
			}
		}
		bool f(matrix &b){
		if(b.sr==sc) return 1;
			return 0;
		}
		matrix add(matrix &b)//加法
		{

		}
		matrix mul(matrix &b)//乘法,a行*b列
		{
			
		}
};
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	return 0;
}
// ExcelFile file("C:\\c+++\\search\\e2.csv");
// "C:\\c+++\\search\\e2.csv"
C:\c+++\search\e2.csv