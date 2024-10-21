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
set<int>s;
int shortest_path(int node , vector<int>&brr , vector<int>&arr , vector<ll>&dist)
{
   set<pair<ll,int>>now;
   now.insert({0 , node});
   dist[node] = 0;
   s.erase(s.begin());
   int n = brr.size();
   vector<int>vis(n-1 , 0);
    
   while(!now.empty()) 
   {
      auto top = *now.begin();
      now.erase(now.begin());
      if(vis[top.second])continue;
      vis[top.second] = 1;
      
      while(!(s.empty()) && *(s.begin())<=top.second){
         
         auto curr = *s.begin();
         s.erase(s.begin());
         dist[curr] = min(dist[curr] , top.first);
         now.insert({dist[curr] , curr});
      }
      if(dist[brr[top.second]] > top.first + arr[top.second]){
          
           dist[brr[top.second]] = top.first + arr[top.second];
           
           now.insert({dist[brr[top.second]] , brr[top.second]});
      }
   }
   
}
void solve(){
  s.clear();
 int n;cin>>n;
 for(int i=1;i<=n;i++){
  s.insert(i);
 }
 vector<int>arr(n+1);
 for(int i=1;i<=n;i++)cin>>arr[i];
 vector<int>brr(n+1);
 for(int i=1;i<=n;i++)cin>>brr[i];
 vector<ll>dist(n+1,LLONG_MAX);
 shortest_path(1 ,  brr , arr , dist);
 ll prev = 0;ll result = 0;
 for(int i=1;i<=n;i++){
   prev+=arr[i];
   if(dist[i]!=LLONG_MAX)
   result = max(result , prev - dist[i]);
 }
   
 cout<<result<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}