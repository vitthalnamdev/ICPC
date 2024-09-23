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
int cnt = 0;
int dfs(ll node , ll parent , vector<ll>adj[] , vector<ll>&arr , int val )
{
    ll curr = arr[node];
    for(auto i:adj[node]){
      if(i==parent)continue; 
      curr^=dfs(i , node , adj , arr , val);
    }
    if(curr==val){
        cnt++;curr = 0;
    }
    return curr;
}

void solve(){
    cnt = 0;
  ll n , k;cin>>n>>k;
  vector<ll>adj[n+1];
  ll val = 0;
  vector<ll>arr(n+1);
  for(ll i=1;i<=n;i++)cin>>arr[i] , val^=arr[i];
  for(ll i=1;i<n;i++){
    ll a , b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if(val==0){
    cout<<"YES"<<endl;return;
  }  
  if(k==2){
    cout<<"NO"<<endl;return;
  }
   dfs(1 , -1 , adj , arr , val);
  if(cnt>=2){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
ll t;cin>>t;
while(t--){
solve();
}
}