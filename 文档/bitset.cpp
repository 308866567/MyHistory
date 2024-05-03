#include <iostream>
#include<bitset>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
void slove2()
{
	//可以用上面位运算时的方法
	bitset<4>a1(string("1011"));
	
	cout<<a1[0]<<endl;//1
	cout<<a1[1]<<endl;//1
	cout<<a1[2]<<endl;//0
	cout<<a1[3]<<endl;//1
	//注意！这两种赋值方式都是反序赋值的
	//所以输出值为1101；
	//可以直接输出a1来输出正序
	
	//bitset支持单点修改
	a1[0]=0;
	cout<<a1[0]<<endl;//0
	cout<<a1<<endl;//0101
}
void slove1()
{
	bitset<8>foo(string("10011011"));
	
	cout<<foo.count()<<endl;//5　　（count函数用来求bitset中1的位数，foo中共有５个１
	cout<<foo.size()<<endl;//8　　（size函数用来求bitset的大小，一共有８位
	
	cout<<foo.test(0)<< endl;//true　　（test函数用来查下标处的元素是０还是１，并返回false或true，此处foo[0]为１，返回true
	cout<<foo.test(2)<<endl;//false　　（同理，foo[2]为０，返回false
	
	cout<<foo.any()<<endl;//true　　（any函数检查bitset中是否有１
	cout<<foo.none()<<endl;//false　　（none函数检查bitset中是否没有１
	cout<<foo.all()<<endl;//false　　（all函数检查bitset中是全部为１
}
void slove3()
{
	bitset <10>bit;
	int n=1;
	int p=1;
	bit.size();        //返回大小（长度）
	bit.count();    //返回1的个数
	bit.any();        //返回是否有1
	bit.none();        //返回是否没有1
	bit.set();        //全部置为1
	bit.set(p);        //将p+1(下标从0开始!!)位置为1
	bit.set(p,n);    //将p+1位置为n
	bit.reset();    //全部置为0
	bit.reset(p);    //将p+1位置为0
	bit.flip();        //全部取反 等同于 (~bit)
	bit.flip(p);    //将p+1位取反
	bit.to_ulong();    //返回转换为 unsigned long  的结果，超范围会报错
	bit.to_ullong();//返回转换为 unsigned long long 的结果，超范围报错
	bit.to_string();//返回转换为 string 的结果
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	string t="1001";//9
	bitset<16> a1(t);//通过string赋值
	cout<<a1<<"\n";
	cout<<a1.count()<<"\n";//输出一的个数
	return 0;
}
