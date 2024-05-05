#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
ll a,b,n;
ll up(double x){
  if(x>(ll) x){
    return x+1;
  }else {
    return (ll) x;
  }
}
int main()
{
    ll ans=0;
    cin>>a>>b>>n;
    ll week=5*a+2*b;
    ans+=7*n/week;
    n%=week;
    if(n<=5*a){
      ans+=up(1.0*n/a);
    }else{
      ans+=5+up(1.0*n/b);
    }
    cout<<ans;
    return 0;
}