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
int ans = 0;
bool dfs(int node , vector<pair<int,int>>adj[] , vector<int>&vis , vector<int>&color)
{
   if(color[node]==1){
      ans++;
   }
   vis[node] = 1;
   for(auto i:adj[node])
   {
      if(!vis[i.first]){
         color[i.first] = color[node]^i.second;    
         bool now = dfs(i.first , adj , vis , color);
         if(now){return true;}
      }else if(vis[i.first] && color[i.first]!=i.second^(color[node]))
      {
         return true;
      }
   }
   return false;    
}
void solve(){
    ans = 0;
    int n ,m;cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int a , b;string c;cin>>a>>b>>c;
        if(c=="imposter")
        {
          adj[a].push_back({b , 1});
          adj[b].push_back({a , 1});
        }else{
          adj[a].push_back({b , 0});
          adj[b].push_back({a , 0});
        }
    }
    vector<int>vis(n+1 , 0);
    vector<int>vis2(n+1 , 0);
    vector<int>color(n+1 , 1);
    vector<int>color2(n+1 , 0);
    int result = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int temp = 0;
            ans = 0;
            bool now1 = dfs(i , adj , vis , color);
            temp = max(temp , ans);
            ans = 0; 
            bool now2 = dfs(i , adj , vis2 , color2);
            temp = max(temp , ans);
            result += temp;
            if(now1&now2){
                cout<<-1<<endl;return;
            }
        } 
    }
    cout<<result<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}