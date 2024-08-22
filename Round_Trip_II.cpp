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
vector<int>path;
bool dfs(int node , vector<int>adj[] , int parent , vector<int>&vis1 , vector<int>&vis2){
  vis1[node] = 1;
  vis2[node] = 1;
  for(auto i: adj[node])
  {
     if(!vis1[i]){
        bool ans = dfs(i , adj , node , vis1 , vis2);
        if(ans){
            if(path[0]==path.back()){
               return true;
            }
            path.push_back(node);
            return true;
        }
     }else if(vis2[i]){
        path.push_back(i);
        path.push_back(node);
        return true;
     }
  }
  vis2[node] = 0;
  return false;
}


void solve(){
  int n , m;cin>>n>>m;
  vector<int>adj[n+1];
  for(int i=0;i<m;i++)
  {
    int a , b;cin>>a>>b;
    adj[a].push_back(b);
    
  }
  vector<int>vis1(n+1 , 0);
  vector<int>vis2(n+1 , 0);
//   bool check = dfs(1 , adj , -1 , vis);
   bool check = false;
  for(int i=1;i<=n;i++)
  {
    if(!vis1[i]){
        check = dfs(i , adj, -1 , vis1 , vis2);
        if(check){break;}
    }
  }
  if(check==false){
    cout<<"IMPOSSIBLE"<<endl;return;
  }
  cout<<path.size()<<endl;
  reverse(path.begin() ,path.end());
  for(auto i:path)
  {
     cout<<i<<" ";
  }cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}