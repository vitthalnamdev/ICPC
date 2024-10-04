// Don't look the rank , if you want a good rank
#include<bits/stdc++.h>
#include<lazysegtree.hpp>
using namespace atcoder;
using namespace std;
  #define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
////--------- DEBUG START---------////
#define debug(x) cerr << #x <<" "; _print(x); cerr<< endl;
void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(long long int a ){cerr<<a;}
// void _print(string a){cerr<<a;}
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
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
 




bool checkoptimized(vector<int>&p , vector<int>&s , vector<int>&time , vector<int>&pref , int ind){
   int n = time.size();
   if(ind-1>=0){
      time[p[ind-1]]++;
      
   }
   time[s[ind]]--;
   int prev = 0;
   for(int i=1;i<n;i++){
      prev+=time[i];
      if(prev>i){
         return false;
      }
   }
   return true;
}
void solve(){
   
   int n;cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];

   int cnt = 0;
   vector<int>pref(n),suff(n);
   int x = n;
   for(int i=0;i<n;i++){
      x = min(x , arr[i]);
      pref[i] = x;
      x = max(x-1 , 0);
   }
   x = n;
   for(int i=n-1;i>=0;i--){
     x = min(x , arr[i]);
     suff[i] = x;
     x = max(x-1 , 0);
   }
   vector<int>time(n+1 , 0);
   time[1]=1;
   for(int i=1;i<n;i++){
     time[suff[i]]++;
   }
 
   vector<int>prev(n+1,0);
   for(int i=1;i<=n;i++){
      prev[i]=(prev[i-1] + time[i] - i);
   }
   

   for(int i=0;i<n;i++){
      if(checkoptimized(pref , suff , time , prev , i)){
         cnt++;
      }
   }   
   cout<<cnt<<endl;
}


int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}