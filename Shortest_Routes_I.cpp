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
vector<ll>shortest_path(int node ,int n , vector<pair<int,int>>adj[]){
  set<pair<ll,ll>>s;
  s.insert({0,node});
  vector<int>vis(n+1 , 0);
  vector<ll>dist(n+1 , LLONG_MAX);
  dist[node] = 0;
  while (!s.empty())
  {
     auto top = *s.begin();
     s.erase(s.begin());
     if(vis[top.second]){
        continue;
     }
     vis[top.second] = 1;
     for(auto i:adj[top.second])
     {
        if(dist[top.second]!=LLONG_MAX && dist[i.first] > dist[top.second] + i.second){
            dist[i.first] = dist[top.second] + i.second;
            s.insert({dist[i.first] , i.first});
        }
     }
  }
  return dist;
  
}
void solve(){
int n;cin>>n;
int m;cin>>m;
vector<pair<int,int>>adj[n+1];
for(int i=0;i<m;i++){
  int a , b , c;cin>>a>>b>>c;
  adj[a].push_back({b,c});
}
 vector<ll>ans = shortest_path(1 , n , adj);
 for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
 }cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}