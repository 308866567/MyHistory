#include <iostream>
#include <vector>
using namespace std;
int main()
{
//    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int x;
    cin >> x;
    int n = 0;
    int t = 1;
    while (t < x)
    {
        t *= 10;
        t++;
		n++;
    }
	//111
	vector<int> ans;
	while(t!=0){
		ans.push_back(t/x);
		t%=x;
		n++;
		//被除数更新
		if(t==0) break;
		t*=10;
		t++;
	}
    for(int i:ans)
		cout<<i<<"";
	cout<<' '<<n;
    return 0;
}
