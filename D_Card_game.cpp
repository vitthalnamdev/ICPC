#include <iostream>
#define ll long long int
using namespace std;
int mod = 998244353;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
ll factorial(ll num){
    ll ans=1;
    for(int i=1;i<=num;i++){
        ans*=i;     ans = ans%998244353;
    }
    return ans;
}
ll ncr(ll n,ll r){
    ll ans = 1;
    ans = factorial(n)*inv(((factorial(r)*factorial(n-r)))%mod);    ans = ans%998244353;
    return ans;
}
int main()
{
   int t;cin>>t;
   while(t--){
       int n;cin>>n;
       ll alex = 0;
       int r = (n/2)-1;int counter = 1,counter2 = 1;
       while(r>=0){
           alex += ncr(n-counter2,r);   alex = alex%998244353;
           counter--;counter2++;
           if(counter == 0){
               counter = 2;
               r-=2;counter2+=2;
           }
       }
       ll total = ncr(n,n/2);
       ll boris = (total-alex-1 + mod )%mod;
       cout<<alex<<" "<<boris<<" "<<1<<endl;
   }
    return 0;
}