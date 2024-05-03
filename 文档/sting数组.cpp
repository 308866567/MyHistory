#include <iostream>
#include <string>
#include <string.h>  //数组赋值
#include <algorithm> //min函数
using namespace std;
int main(void)
{
    cout << "go";
    string a = "a";
    string b = "b";
    // cin >> a;输入赋值
    a = b; //直接赋值
    char c[4];
    /*初始化*/memset(c, 'c', 4 * sizeof(char)); //(数组, 初始数,个数);
    cout << a + b;                    //直接拼接
    int c[] = {5, 4, 3, 2, 1};
    int x = min_element(c + 0, c + 3) - c;
    return 0;
}