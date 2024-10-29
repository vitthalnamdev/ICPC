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
//flags to use g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
void solve(){
  int n , m , sx , sy , ex , ey;
  string direction;
  cin>>n>>m>>sx>>sy>>ex>>ey>>direction;
  vector<vector<pair<int,int>>>vis(n+1 , vector<pair<int,int>>(m+1 , { -1 , -1}));
  vector<int>dir = {(direction[0]=='U'?1:0) , (direction[1]=='R'?1:0)};
  auto get_dir = [&](vector<int>curr)->pair<int,int>{
      pair<int,int>ans = {curr[0]==0?1:-1 , curr[1]==0?-1:1};
      return ans;
  };
  auto change_dir = [&](vector<int>curr , int currx , int curry)->vector<int>{       
      if((currx==1 && curry==1) || (currx==1 && curry==m) || (currx==n && curry==1) || (currx==n && curry==m)){
         vector<int>ans = {curr[0]^1 , curr[1]^1};
         return ans;
      }
      if(currx==n || currx==1){
         vector<int>ans = {curr[0]^1 , curr[1]};
         return ans;
      }
          
      if(curry==m || curry==1){
         vector<int>ans = {curr[0] , curr[1]^1};
         return ans;
      }
      return curr;
  };
  auto bfs = [&]()->int{
      int ans=-1;
      int cnt=0;
      int x = sx , y = sy;    
      while(vis[x][y]!=make_pair(dir[0] , dir[1])){ 
          vis[x][y] = {dir[0] , dir[1]};
          auto nxt = get_dir(dir);
          auto newdir = dir;      
          if((x+nxt.first>n) || (x+nxt.first<1) || (y+nxt.second>m) || (y+nxt.second<1)){
            newdir = change_dir(dir , x , y);
          }
          if(dir!=newdir){cnt++;dir = newdir;}
          nxt = get_dir(dir);
          x+=nxt.first;y+=nxt.second;    
          if(x==ex && y==ey){ans = cnt;break;}
      }
      return ans;
  };
  auto prevdir = dir;
  int ans = bfs();
 
  if(ans!=-1){
    cout<<ans<<endl;
    return;
  }
  dir = prevdir;
  dir[0]^=1;dir[1]^=1;
  ans = bfs();
  cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}