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
  int N;cin>>N;
  vector<int>arr(2*N);
  for(int i=0;i<2*N;i++)cin>>arr[i];
  int mx = 0;
  int ind = 0;
  vector<int>cnt(2*N+1,0);
  for(int i=0;i<2*N;i++){
     if(arr[i]<=mx){
       cnt[ind]++;
     }else{
       cnt[++ind]++;
       mx = arr[i];
     }
  }
  vector<int>vis(2*N+1 , 0);
  vis[0] = 1;
  vector<vector<int>>from(2*N+1 , vector<int>(2*N+1 , 0));
  vector<int>prefix(ind+1 , 0);
  prefix[0] = 0;
  for(int i=1;i<=ind;i++){
    prefix[i] = prefix[i-1] + cnt[i-1];
    for(int j=N;j>=cnt[i];j--)
    {
       if(!vis[j] && vis[j-cnt[i]]){
          vis[j] = 1;from[j][cnt[i]]=1;
       }
    }
  }
  if(vis[N]==0){
    cout<<-1<<endl;return;
  }
  int p1 = N;
  vector<int>col(2*N+1 , 0);
  int curr = N;
  for(int i=ind;i>=1;i--)
  {
     
     if(from[curr][cnt[i]]){
        for(int j=prefix[i];j<=(prefix[i] + cnt[i]-1);j++){
           col[j] = 1;
        }
        curr-=cnt[i];
     }
     if(curr<=0){
       break;
     }
  }
 
  for(int i=0;i<2*N;i++){
    if(col[i])cout<<arr[i]<<" ";
  }cout<<endl;
  for(int i=0;i<2*N;i++){
     if(col[i]==0)cout<<arr[i]<<" ";
  }cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}