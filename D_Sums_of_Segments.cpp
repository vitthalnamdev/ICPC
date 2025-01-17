// Don't look the rank , if you want a good rank
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
  #define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
////--------- DEBUG START---------////
#define debug(x) cerr << #x <<" "; _print(x); cerr<< endl;
void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(long long int a ){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr << a;}
template<class T1 , class T2>void _print(pair<T1,T2>a){cerr<<"{ ";cerr<<a.first<<" "<<a.second;cerr<<" }";}
template<class T>void _print(vector<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(set<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(multiset<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
////------DEBUG END---------////
int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
long long binpow(long long a, long long b, long long m) {
a %= m;
long long res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
//flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
void solve(){
   ll n;cin>>n;
   vector<ll>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   vector<ll>prefix(n+1);
   for(int i=0;i<n;i++){
     prefix[i+1] = arr[i]*(n-i);
   }
   for(int i=n-1;i>=1;i--)
   {
     prefix[i]+=prefix[i+1];
   }
   int q;cin>>q;
   vector<ll>ind(n+1 , 0);
   for(int i=1;i<=n;i++){
     ind[i]=(ind[i-1] + n-i+1);
   }
   vector<ll>prefsum(n+1 , 0);
   for(int i=1;i<=n;i++){
     prefsum[i] = prefsum[i-1] + prefix[i];
   }
   
   vector<vector<ll>>count(n+1 , vector<ll>(30 , 0));
   for(int i=1;i<=n;i++){
     for(int j=-10;j<=10;j++){
       count[i][j+10] = count[i-1][j+10];
     }
     count[i][arr[i-1] + 10]++;
   }
     
   auto sum = [&](ll i)->long long int{
      if(i<=0){
         return 0;
      }
      auto index = lower_bound(ind.begin() , ind.end() , i) - ind.begin();
      if(ind[index]==i){
        return prefsum[index];
      } 
      ll prevsum = prefsum[index];
      ll leftelements = i - ind[index - 1];

      ll r = leftelements + index ;
       
      prevsum-=(prefix[r]);
      
       
      for(int i=-10;i<=10;i++){
        ll cnt = (r-1>=0?count[r-1][i+10]:0) - (index-1>=0?count[index-1][i+10]:0);
        prevsum-=((n-leftelements-index+1)*(i)*(cnt));
      }
      return prevsum;  
   };

 
   while(q--)
   {
       ll l , r;cin>>l>>r;
       cout<<sum(r) - sum(l-1)<<endl;    
   }
 
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}