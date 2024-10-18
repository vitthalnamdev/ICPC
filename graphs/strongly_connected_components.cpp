//using targan's algorithm.
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
int cnt = 0;
int dfs(int node , vector<int>&vis , vector<int>&vis2 , vector<int>&ids , vector<int>adj[])
{
    ids[node] = ++cnt;
    vis[node] = 1;
    vis2[node] = 1;
    s.insert(node);
    for(auto i:adj[node])
    {
        if(!vis[i]){
            dfs(i , vis , vis2 , ids , adj);
            if(vis2[i])
            ids[node] = min(ids[node] , ids[i]);
        }else if(vis2[i]){
            ids[node] = min(ids[node] , ids[i]);
        }
    }
    vis2[node] = 0;
}
void solve(){
   int N;cin>>N;
   int M;cin>>M;
   vector<int>adj[N+1];
   for(int i=0;i<M;i++){
     int a , b;cin>>a>>b;
     adj[a].push_back(b);
   }
   vector<int>vis(N+1 , 0);
   vector<int>vis2(N+1 , 0);
   vector<int>ids(N+1 , INT_MAX);
   for(int i=1;i<=N;i++){
     if(!vis[i]){
         dfs(i , vis , vis2 , ids , adj);
     }
   }
   set<int>ans;
   for(int i=1;i<=N;i++){
    cout<<ids[i]<<" ";
      ans.insert(ids[i]);
   }cout<<endl;
   cout<<ans.size()<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}