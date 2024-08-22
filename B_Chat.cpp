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
void yeh_bhi_krr_lete_hain(){
int n , k;cin>>n>>k;
vector<int>messages(n+1);
for(int i=1;i<=n;i++){
    cin>>messages[i];
}
vector<int>dp(n+1 , 0);
for(int i=1;i<=n;i++){
  if(messages[i]==0){
       dp[i] =  min(n , i+k) - max(1 , i-k) +1;
  }else{
   dp[i] = dp[messages[i]] + min(n , i+k) - min(n,max(max(1 , i-k) , messages[i]+k)); 
   if(min(n , messages[i]+k) < max(1 , i-k))dp[i]++;
  }
}
for(int i=1;i<=n;i++){  
    cout<<dp[i]<<" ";
}cout<<endl;
}


/*
   i am on ith index , i can read i-k to i+k messages total of i+k-(i-k) = k+k+1; total without going to link 
   //  dp[arr[i]]  + 2*k + 1;
   // but there is overcount 
   // dp[i] = dp[arr[i]] + (min(n , i+k) - max((i-k , arr[i]+k)); 
   // if(arr[i]+k < i-k)dp[i]++;

*/


/*
2 0
0 1


*/
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
yeh_bhi_krr_lete_hain();
}
}