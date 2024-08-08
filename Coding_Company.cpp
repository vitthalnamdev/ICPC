// Don't see the rank , if you want a good rank
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
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
void yeh_bhi_krr_lete_hain(){
   ll n;cin>>n;
   ll x;cin>>x;
   vector<ll>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   sort(arr.begin() , arr.end());
   vector<vector<ll>>dp(n+1 , vector<ll>(x+1 , 0));
   dp[0][0] = 1;
   debug(arr);
   for(int i=1;i<n;i++){
      for(int j=i-1;j>=0;j--){
         for(int k=0;k<=x;k++){
           int num = arr[i] - arr[j] + k;
            if(j==i-1){
                dp[i][k] += (dp[j][k]);
                dp[i][k]%=mod;
            }
            if(num<=x){
                dp[i][num]+=(dp[j][k]);
                dp[i][num]%=mod;
            }
         }
      }
   }
   
   ll ans = 0;
   for(int i=0;i<=x;i++){
        ans+=(dp[n-1][i]);
        ans%=mod;
   }
   cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
yeh_bhi_krr_lete_hain();
}
}