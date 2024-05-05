#include <iostream>
using namespace std;
typedef long long ll;
const ll N=1e5;
int w[N]={1,9,9*9,9*9*9};
int main()
{
  cout<<2*w[0]+2*w[1]+2*w[3];
  return 0;
}