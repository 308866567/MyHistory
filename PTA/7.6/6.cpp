#include <iostream>
#include <vector>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
int n;
vector<int> ans;
bool used[N] = {0, 0};
int main()
{
//		freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	int n;
	cin >> n;
	//添加质数
	//一个质数不问的话,将无法和1区分开
	
	//添加质数的次方
	//次方不询问的话,无法跟质数^1区分开(找规律)
	//比如4,无法通过问2判断,2和4的判断是一样的
	
	
	//其他的数(指非质数,因子>=2的)都可以转换成p1^k*p2^k的形式。
	//设m不是质数时,m的质因子有(1,m,x,m/x);(x为质数)
	
	//m是质数时,因子为(1,m)
	//m^k是质数的次方时,因子为(1,m^k,m)
	
	//整除 a 且整除 b 自然整除 a×b，所以无需询问。
	//比如6=2^1*3^1,询问6的结果可以由问2和问3得到,所以6无需询问
	//因为任意一个正整数都可以表示为多个质数的次方相乘的形式，
	//这被称为质因数分解或素因数分解。
	for (int i = 2; i <= n; i++)
	{
		if (used[i])//不是质数
			continue;
		for (int j = i; j <= n; j *= i)
		{
			ans.emplace_back(j);//添加质数的次方
		}
		//用当前添加的质数筛去其倍数
		for (int j = i + i; j <= n; j += i) //埃氏筛质数
		{
			used[j] = 1;
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
