#include <map>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    map<int, int> arr;
    map<int, int>::iterator it=arr.begin();
    for ( ;it != arr.end(); it++)
    {
        it->first;      //键,只读
        it->second = 3; //值,可修改
    }
    return 0;
}