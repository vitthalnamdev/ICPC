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
vector<int>adj[100010];
vector<int>dist(100010 , 0);
vector<int>dall(100010 , 0);
vector<int>nums(100010 , 0);
void dfs(int node , int parent)
{
    for(auto i: adj[node])
    {
       if(i==parent){continue;}
       dfs(i , node);
       dist[node] = max(dist[node] , dist[i] + 1);
    }
}
void rerooting(int node , int parent , int mx ){
  
  dall[node] = max(dist[node] , mx);

  vector<int>sons;
  int max1 = INT_MIN;int max2 = INT_MIN;
  for(auto i: adj[node])
  {
     if(i==parent){continue;}
     if(dist[i]  > max1){
        max2 = max1;
        max1 = dist[i];
     }else if(dist[i] > max2){
         max2 = dist[i];
     }
     sons.push_back(i);
  }
  
  for(auto i: sons){
    rerooting(i, node , max(mx + 1 , (dist[i]==max1?max2:max1) + 2));
  }
}
void yeh_bhi_krr_lete_hain(){
  int n;cin>>n; 
  for(int i=1;i<=n-1;i++){
     int a , b;cin>>a>>b;
     adj[a].push_back(b);
     adj[b].push_back(a);
  }
  dfs(1 , -1);
  rerooting(1 , -1 , 0);
  for(int i = 1;i<=n;i++){
     nums[dall[i]]++;
  }
  
  for(int i = n-1;i>=1;i--)
  {
     nums[i]+=nums[i+1];
  }
  
  for(int i =1 ;i<=n;i++)
  {
    if(nums[i]==0){
      cout<<n<<" ";
    }else{
      cout<<n-nums[i]+1 <<" ";
    }
  }cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
yeh_bhi_krr_lete_hain();
}
}