#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin>>n;
    char x;
    double h;
    int ans;
    while (n--)
    {
        cin>>x;
        cin>>h;
        if(x=='M'){
            printf("%.2f\n",h/1.09 );
        }else{
            printf("%.2f\n",h*1.09 );
        }
    }
    
    return 0;
}