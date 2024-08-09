// Don't look up the rank , if you want a good rank
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
vector<int>adj[200010];
vector<int>vis(200010 , 0);
vector<int>dist(200010 , 0);
vector<int>vis2(200010  , 0);
vector<int>ans(200010 , 0);
int val=-1;
bool dfs(int node , int cnt )
{
    dist[node] = cnt;
    vis[node] = 1;
    vis2[node] = 1;
    bool check = false;
    for(auto i: adj[node])
    {
      if(!vis[i])
      {
        check = dfs(i , cnt + 1);
        if(check==true){
            ans[node] = ans[i];
            break;
        }else{
            ans[node] = ans[i] + 1;
        }
      }else if(vis2[i]){
         val = i;
         ans[node] = dist[node] - dist[i] + 1;
         check = true;
         break;
      }else{
         ans[node] = ans[i] + 1;check = false; break;
      }
    }
    if(val==node){
      check=false;
    }
    vis2[node] = false;
    return check;
}
void yeh_bhi_krr_lete_hain(){
 int n;cin>>n;
 for(int i = 1;i<=n;i++){
      int x;cin>>x;
     adj[i].push_back(x);
 }
 for(int i = 1;i<=n;i++){
    if(!vis[i])
    { 
       dfs(i,0);
    }
 }
 for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
yeh_bhi_krr_lete_hain();
}
}