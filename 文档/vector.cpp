#include <iostream>
#include <stack>  //c��ջ������ȳ�
#include <queue>  //c�Ķ��У��Ƚ��ȳ�
#include <vector> //����
#include <algorithm>
using namespace std;
int aa(vector<int>&a, vector<int>&b)
{
	vector<int> b(10, 1);	//������10������Ԫ�ص�����,�Ҹ���ÿ��Ԫ�صĳ�ֵΪ1
	vector<int> a(b);	//��b����������a���������帴���Ը�ֵ
	vector<int> aaa(b.begin(), b.begin() + 3);	//������aֵΪb�е�0������2������3����Ԫ��
	int i = 1;
	int c[10] = {0};
	a[i];								   //����a�ĵ�i��Ԫ�أ����ҽ���a[i]����
	a.insert(a.begin() + 1, 5);			   //��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò�����ֵ5
	a.clear();							   //���a�е�Ԫ��
	a.empty();							   //�ж�a�Ƿ�Ϊ�գ����򷵻�ture,�����򷵻�false
	a.pop_back();						   //ɾ��a���������һ��Ԫ��
	a.erase(a.begin() + 1, a.begin() + 3); //ɾ��a�е�1�����ӵ�0�����𣩵���2��Ԫ��
	a.push_back(5);						   //��a�����һ�����������һ��Ԫ��
	a.insert(a.begin() + 1, 5);			   //��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò�����ֵ5
	a.insert(a.begin() + 1, 3, 5);		   //��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò���3��������ֵ��Ϊ5
	// cΪ���飬��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò���c�ĵ�3��Ԫ�ص���5��Ԫ��
	a.insert(a.begin() + 1, c + 3, c + 6);
	a.size();		 //����a��Ԫ�صĸ�����
	a.resize(10, i); //��a������Ԫ�ظ�������10��������ɾ�����򲹣���ֵΪi
	a.reserve(100);	 //��a��������capacity��������100
	a.swap(b);		 // bΪ��������a�е�Ԫ�غ�b�е�Ԫ�ؽ��������Խ���
	reverse(a.begin(), a.end());	//��a�еĴ�a.begin()������������a.end()��������������Ԫ�ص��ã���������
	return 0;
}
int cc(void)
{
	stack<int> name1; //�����洢int���͵�ջ������ȳ�
	int a = 1;
	name1.push(a); //ջ������
	name1.pop();   //�Ƴ�ջ��
	//
	queue<int> name2;
	name2.push(a); //ĩβ����
	name2.pop();   //�Ƴ���ͷ
	return 0;
}
int main(void)
{
	return 0;
}
