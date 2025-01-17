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
  ll n , q;cin>>n>>q;
  vector<ll>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  vector<ll>pref(n+1);
  pref[0] = 0;
  for(int i=0;i<n;i++){
    pref[i+1] = pref[i] + arr[i];
  }
  auto find = [&](int start , int l)->long long int{
     if(l<0){
        return 0;
     }
      ll curr = 0;
      ll ind = start + 1;
      ll len = n - ind + 1;
     
      ll pos = l%n+1;
     
      curr+=(pref[min(n , ind + pos - 1)] - pref[start]); 
      if(len<pos){
        int left = pos - len;
        curr+=(pref[left]);
      }
      return curr;
  };
  
  while(q--)
  {
    int l , r;cin>>l>>r;
    ll start = (l-1)/n;
    ll end = (r-1)/n;
    ll ans = 0;
    if(start==end){
      ll starting = find(start , l-2);
      ll ending = find(end , r-1);
      ans+=(ending - starting);
    }else{
      ans+=(pref[n] - find(start , l-2));
      ans+=(find(end , r-1));
    }
    ll len = max(0LL,end - start - 1);
    
    ans+=(pref[n]*len);
    cout<<ans<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}