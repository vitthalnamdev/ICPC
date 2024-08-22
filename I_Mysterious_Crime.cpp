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
int mod = 1e9+9;
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
 

  vector<ll> compute_hash(vector<ll>&s) {
    const ll p = 1e9+7;
    const ll m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    int n = s.size();
    vector<ll>ans(n+1);
   
    for (int i = 1;i<=n;i++) {
        hash_value = (hash_value + (s[i]) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        ans[i] = hash_value;
    }
    ans[0] = 0;
    return ans;
}
bool check(vector<vector<ll>>&hash , vector<vector<ll>>&pos , ll hash_value , int last , int sz , int n , int m ){
     

       for(int i=1;i<=m;i++)
       {
          int lastval = pos[i][last];
          
          if(lastval - sz < 0){
            return false;
          }
           
          int x = lastval - sz;
          ll value = ((hash[i][lastval] - hash[i][lastval-sz]))*(inv(binpow(1e9+7 ,x , mod)))%mod;
           
          if(value!=hash_value){
            return false;
          }
       }
        
       return true;
}


void yeh_bhi_krr_lete_hain(){
    int n;cin>>n;int m;cin>>m;
    vector<vector<ll>>arr(m+1 , vector<ll>(n+1));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<ll>>hash(m+1 , vector<ll>(n+1));
    for(int i=1;i<=m;i++){
        hash[i] = compute_hash(arr[i]);
    }
  
    vector<vector<ll>>pos(m+1 , vector<ll>(n+1));
     for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
        { 
             pos[i][arr[i][j]] = j;
        }
     }
     ll ans = 0;
       
     ll prev = 0;
     ll hash_value = 0;
     ll p = 1e9+7;
     ll p_pow = 1;
    for(int i=1;i<=n;i++)
    {
      prev++;
      hash_value = (hash_value + ((arr[1][i]) * p_pow)) % mod;
        
          p_pow = (p_pow * p) % mod;
          
          if(!check(hash , pos , hash_value , arr[1][i] , prev , n , m )){
               
              p_pow = 1e9+7;
              ans+=((prev*(prev-1))/2);
              hash_value = arr[1][i];
              prev = 1;
          }
    }

    ans+=(prev*(prev+1))/2;
  cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
yeh_bhi_krr_lete_hain();
}
}