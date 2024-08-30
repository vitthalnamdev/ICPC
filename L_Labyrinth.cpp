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
vector<int>adj[200010];
vector<int>from(200010 ,0);
vector<int>vis(200010,0);
vector<int>parent(200010,0);
void dfs(int node , int s , int father , int start)
{
   if(node==start){
      return;
   }
   if(vis[node] && from[node]^father)
   {
      cout<<"Possible"<<endl;
      vector<int>a,b;
      a.push_back(node);
      b.push_back(node);
      while(parent[a.back()]){
         a.push_back(parent[a.back()]);
      }
      parent[node] = s;
      while(parent[b.back()]){
         b.push_back(parent[b.back()]);
      }
      std::reverse(a.begin(),a.end());
      std::reverse(b.begin(),b.end());
      cout<<a.size()<<endl;
      for(auto i:a)cout<<i<<" ";
      cout<<endl<<b.size()<<endl;
      for(auto i:b){
         cout<<i<<" ";
      }cout<<endl;
      exit(0);
   }
   if(from[node]){
      return;
   }
   parent[node] = s;
   from[node] = father;
   vis[node] = 1;
   for(auto i:adj[node])
     dfs(i , node , father , start);
}
void solve(){
 int n , m , s;cin>>n>>m>>s;
 for(int i=0;i<m;i++)
 {
   int a , b;cin>>a>>b;
   adj[a].push_back(b);
 }
 for(auto i:adj[s])
 {
   dfs(i , s , i , s);
 }
 cout<<"Impossible"<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}