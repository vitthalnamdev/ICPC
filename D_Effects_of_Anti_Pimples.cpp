// Don't look the rank , if you want a good rank
#include<bits/stdc++.h>
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
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
void solve(){
int mod = 998244353;
  int n;cin>>n;
  vector<pair<ll,ll>>arr(n+1);
  for(int i=1;i<=n;i++)cin>>arr[i].first,arr[i].second=i;  
  auto brr = arr;
  arr[0].first = INT_MAX;
  brr[0].first = INT_MAX;
  sort(arr.begin() , arr.end() , [](pair<int,int> a , pair<int,int>b){return a.first>b.first;});
  ll ans = 0;
  for(int i=1;i<=n;i++){
    int ele = arr[i].second;
    for(int j=1;j*j<=ele;j++){
      if((ele%j)==0){
        brr[j].first = max(brr[j].first , arr[i].first);
        int nex = ele/j;
        brr[nex].first = max(brr[nex].first , arr[i].first);
      }
    }
  }
  sort(brr.begin() , brr.end(),[](pair<int,int>a , pair<int,int>b){return a.first>b.first;});
   
  for(int i=1;i<=n;i++){
     ll mx = brr[i].first; 
     ans+=((mx*binpow(2,n-i,mod))%mod);
     ans%=mod;
  }
  cout<<ans<<endl;
   
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}