#include <iostream>
#include <string>
#include <string.h>  //���鸳ֵ
#include <algorithm> //min����
using namespace std;
int main(void)
{
    cout << "go";
    string a = "a";
    string b = "b";
    // cin >> a;���븳ֵ
    a = b; //ֱ�Ӹ�ֵ
    char c[4];
    /*��ʼ��*/memset(c, 'c', 4 * sizeof(char)); //(����, ��ʼ��,����);
    cout << a + b;                    //ֱ��ƴ��
    int c[] = {5, 4, 3, 2, 1};
    int x = min_element(c + 0, c + 3) - c;
    return 0;
}