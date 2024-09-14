// Don't look the rank , if you want a good rank
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
////--------- DEBUG START---------////
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
void _print(int a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(long long int a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(bool a) { cerr << a; }
template <class T1, class T2>
void _print(pair<T1, T2> a)
{
  cerr << "{ ";
  cerr << a.first << " " << a.second;
  cerr << " }";
}
template <class T>
void _print(vector<T> &a)
{
  cerr << "[ ";
  for (T i : a)
  {
    _print(i);
    cerr << " ";
  }
  cerr << " ]";
}
template <class T>
void _print(set<T> &a)
{
  cerr << "[ ";
  for (T i : a)
  {
    _print(i);
    cerr << " ";
  }
  cerr << " ]";
}
template <class T>
void _print(multiset<T> &a)
{
  cerr << "[ ";
  for (T i : a)
  {
    _print(i);
    cerr << " ";
  }
  cerr << " ]";
}
////------DEBUG END---------////
int mod = 1e9 + 7;
ll inv(ll a)
{
  return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}
long long binpow(long long a, long long b, long long m)
{
  a %= m;
  long long res = 1;
  while (b > 0)
  {
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

bool iscycle(int node , vector<int>adj[] , vector<int>&vis , vector<int>&vis2) 
{
   
  vis[node] = 1;
  vis2[node] = 1;
  for(auto i:adj[node])
  {
     if(!vis[i])
     {
       bool now = iscycle(i , adj , vis , vis2);
       if(now==false){
         vis2[node] = 0;
         return false;
       }
     }else if(vis2[i]==1){
       return false;
     }
  }
  vis2[node] = 0;
  return true;
}
 

void solve()
{
   int n , k;cin>>n>>k;
   vector<int>adj[n+1];
   for(int i=0;i<k;i++){
     vector<int>curr(n);
     for(int j=0;j<n;j++){
         cin>>curr[j];
     }
     for(int l=1;l<n-1;l++){
        adj[curr[l]].push_back(curr[l+1]);
     }
   }
    
   vector<int>vis(n+1 , 0);
   vector<int>vis2(n+1 , 0);
   bool check = 1;
   
   for(int i=1;i<=n;i++){
    if(!vis[i]){
       check = iscycle(i , adj , vis , vis2);
       if(check==0){
          break;
       }
    }
   }
   if(check){
    cout<<"YES"<<endl;
   }else cout<<"NO"<<endl;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}