#include <iostream>
#include<bitset>
typedef long long ll;
const ll N = 1e3 + 1;
using namespace std;
void slove2()
{
	//����������λ����ʱ�ķ���
	bitset<4>a1(string("1011"));
	
	cout<<a1[0]<<endl;//1
	cout<<a1[1]<<endl;//1
	cout<<a1[2]<<endl;//0
	cout<<a1[3]<<endl;//1
	//ע�⣡�����ָ�ֵ��ʽ���Ƿ���ֵ��
	//�������ֵΪ1101��
	//����ֱ�����a1���������
	
	//bitset֧�ֵ����޸�
	a1[0]=0;
	cout<<a1[0]<<endl;//0
	cout<<a1<<endl;//0101
}
void slove1()
{
	bitset<8>foo(string("10011011"));
	
	cout<<foo.count()<<endl;//5������count����������bitset��1��λ����foo�й��У�����
	cout<<foo.size()<<endl;//8������size����������bitset�Ĵ�С��һ���У�λ
	
	cout<<foo.test(0)<< endl;//true������test�����������±괦��Ԫ���ǣ����ǣ���������false��true���˴�foo[0]Ϊ��������true
	cout<<foo.test(2)<<endl;//false������ͬ��foo[2]Ϊ��������false
	
	cout<<foo.any()<<endl;//true������any�������bitset���Ƿ��У�
	cout<<foo.none()<<endl;//false������none�������bitset���Ƿ�û�У�
	cout<<foo.all()<<endl;//false������all�������bitset����ȫ��Ϊ��
}
void slove3()
{
	bitset <10>bit;
	int n=1;
	int p=1;
	bit.size();        //���ش�С�����ȣ�
	bit.count();    //����1�ĸ���
	bit.any();        //�����Ƿ���1
	bit.none();        //�����Ƿ�û��1
	bit.set();        //ȫ����Ϊ1
	bit.set(p);        //��p+1(�±��0��ʼ!!)λ��Ϊ1
	bit.set(p,n);    //��p+1λ��Ϊn
	bit.reset();    //ȫ����Ϊ0
	bit.reset(p);    //��p+1λ��Ϊ0
	bit.flip();        //ȫ��ȡ�� ��ͬ�� (~bit)
	bit.flip(p);    //��p+1λȡ��
	bit.to_ulong();    //����ת��Ϊ unsigned long  �Ľ��������Χ�ᱨ��
	bit.to_ullong();//����ת��Ϊ unsigned long long �Ľ��������Χ����
	bit.to_string();//����ת��Ϊ string �Ľ��
}
int main()
{
//	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	string t="1001";//9
	bitset<16> a1(t);//ͨ��string��ֵ
	cout<<a1<<"\n";
	cout<<a1.count()<<"\n";//���һ�ĸ���
	return 0;
}
