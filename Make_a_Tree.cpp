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
int cnt;
vector<vector<int>>ans;
int color = 1;
void dfs(int node , int parent , vector<int>adj[] , vector<int>&curr , vector<vector<int>>&included , vector<int>&vis){
    for(auto i:adj[node])
    {
        if(i==parent)continue;
        if((vis[i]==0)  && (vis[node]==0) && (included[i][node]==0)){
            cnt++;
            included[i][node] = 1;included[node][i] = 1;
            curr[i] = color;curr[node] = color;
            vis[i] = 1;vis[node] = 1;
            color++;
        }
        dfs(i , node , adj , curr ,  included , vis);
    }
}

void solve(){
  cnt = 0;
  ans.clear();
  int n;cin>>n;
  vector<int>adj[n+1];
  for(int i=1;i<n;i++){
    int a , b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<vector<int>>included(n+1 , vector<int>(n+1 , 0));
  for(;cnt<n-1;){
    color = 1;
    vector<int>curr(n+1 , 0);
    vector<int>vis(n+1 , 0);
    dfs(1 , -1 , adj , curr ,  included , vis);
    for(int j=1;j<=n;j++){
       if(curr[j]==0)curr[j] = ++color;
    }
    ans.push_back(curr);
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    for(int j=1;j<=n;j++){
        cout<<ans[i][j]<<" ";
    }cout<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}