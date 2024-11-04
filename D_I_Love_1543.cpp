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
void solve(){
 int n , m;cin>>n>>m;
 vector<string>arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 int p1 = 0 , p2 = 0;
 vector<vector<int>>vis(n , vector<int>(m , 0));
 int ans = 0;
 while(vis[p1][p2]==0){
    string curr = "";
    for(int i=n-p1-1;i>=p1;i--){
     if(vis[i][p2]==0)
      curr+=(arr[i][p2]);
      vis[i][p2] = 1;
    }
    
    for(int j=p2;j<m-p2;j++){
     if(vis[p1][j]==0)
      curr+=(arr[p1][j]);
      vis[p1][j] = 1;
    }
    
     for(int i=p1;i<n-p1;i++){
      if(vis[i][m-p2-1]==0)
      curr+=(arr[i][m-p2-1]);
      vis[i][m-p2-1] = 1;
    }
    
    for(int j=m-p2-1;j>=0;j--){
     if(vis[n-p1-1][j]==0)
      curr+=(arr[n-p1-1][j]);
      vis[n-p1-1][j] = 1;
    }
    if(curr.length()<4){
         continue;
    }
    for(int i=0;i<3;i++){
        curr+=curr[i];
    }
    
    for(int i=0;i<curr.length();i++){
        if(curr.substr(i , 4)=="1543"){
            ans++;
        }
    }
   
    p1++;p2++;
 }
 cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}