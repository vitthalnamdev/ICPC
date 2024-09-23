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
vector<int>leaves;
int w = 0;
void dfs(int node , int parent , vector<int>adj[] , string &s)
{
   int cnt = 0;
   for(auto i:adj[node]){
      if(i==parent)continue;
      cnt++;
      dfs( i , node , adj , s);
   }
   if(cnt==0){
     leaves.push_back(node);  
   }else if(s[node-1]=='?')
   {
     w++;
   }
}
void solve(){
  leaves.clear();
  w =0;
  int n;cin>>n;
  vector<int>adj[n+1];
  for(int i=1;i<n;i++){
    int a , b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  string s;cin>>s;
  dfs(1 , -1 , adj , s);
   
  int ones = 0 , zeroes = 0 , questionmark = 0;
  for(int i=0;i<leaves.size();i++){
     if(s[leaves[i]-1]=='0'){
       zeroes++;
     }else if(s[leaves[i]-1]=='1'){
       ones++;
     }else{
       questionmark++;
     }
  }
  
  if(s[0]=='0')
  {
     cout<<ones+questionmark/2 + questionmark%2<<endl;
  }else if(s[0]=='1')
  {
    cout<<zeroes + questionmark/2 + questionmark%2<<endl;
  }else{
    if(zeroes==ones){
      if(w%2==0){
        cout<<max(ones , zeroes) + questionmark/2 + questionmark%2<<endl;
      }else{
        cout<<max(ones , zeroes) + questionmark/2<<endl;
      }
    }else{
      cout<<max(ones , zeroes) + questionmark/2<<endl;
    }
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}