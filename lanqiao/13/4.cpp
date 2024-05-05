#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
ll n;
vector<ll> ans[N];
int main(){
    cin>>n;
    if(n==1){
      cout<<1;
      return 0;
    }
    ll d=1;
    ll now=1;
    ll a=1;
    for(int i=1;i<=10*n;i++){
      if(now==n+1){
        a=-1;
        now=n-1;
      }
      if(now==0){
          a=1;
          now=2;
      }
      ans[now].push_back(d++);
      now+=a;
    }
    for(int i=1;i<=n;i++){
      // cout<<ans[i][1]-ans[i][0]<<"\n";
       cout<<max(ans[i][1]-ans[i][0],ans[i][2]-ans[i][1])<<'\n';
    }
    // cout<<"\n";
    // for(ll i=1;i<=n;i++){
    //   cout<<2*max(i-1,n-i)<<'\n';
    // }
  return 0;
}