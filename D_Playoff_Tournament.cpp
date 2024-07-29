 
#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 1e9+7;
int tree[20000001];
string s;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
inline void vitthal(int i){
   tree[i] = tree[i*2]*(s[i]!='0') + tree[i*2 + 1]*(s[i]!='1');
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
   int n;cin>>n;
   cin>>s;
   reverse(s.begin() , s.end());
   n = s.length();
   s = '!' + s;
   for(int i=n*4;i>=0;i--){
     if(i>n){
        tree[i] = 1;
     }else{
        vitthal(i );
     }
   }
   int q;cin>>q;
   while(q--)
   {
     int ind ;char val;
     cin>>ind>>val;
     ind = n - ind + 1;
     s[ind] = val;
     while(ind>=1)vitthal(ind ),ind/=2;
     cout<<tree[1]<<endl;
   }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}
 