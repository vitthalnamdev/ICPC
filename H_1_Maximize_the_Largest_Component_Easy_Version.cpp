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

bool istrue(int x , int y , int n ,int m )
{
   return x>=0 && y>=0 && x<n && y<m;
}
void dfs(int x , int y , vector<string>&arr , vector<vector<int>>&vis , int cnt , vector<vector<int>>&value)
{
     
    vis[x][y] = 1;
    value[x][y] = cnt;
    vector<int>dir = {-1 , 1};
    for(auto i:dir)
    {
        
        if(istrue(x+i , y , arr.size() , arr[0].length()) && arr[x+i][y]=='#' && !(vis[x+i][y]))
        {
            dfs(x+i , y , arr , vis , cnt , value);
        }
        if(istrue(x , y+i , arr.size() , arr[0].length()) && arr[x][y+i]=='#' && !(vis[x][y+i]))
        { 
            dfs(x , y+i , arr , vis , cnt , value);
        }
    }
}

void solve(){
 int n , m;cin>>n>>m;
 vector<string>arr(n);
 for(int i=0;i<n;i++)cin>>arr[i];
 vector<vector<int>>vis(n , vector<int>(m));
 int cnt = 0;
 vector<vector<int>>value(n+1 , vector<int>(m+1 , 0));
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       if(!vis[i][j] && arr[i][j]=='#')
       {
          ++cnt;
          dfs(i , j ,  arr , vis , cnt , value);
       }
    }
 }
    
 vector<int>cntvalues(cnt+1 , 0);
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cntvalues[value[i][j]]++;
    }
 }
  
 int result = 0;
 for(int i=0;i<n;i++){
    set<int>s;int ans = 0;
    for(int j=0;j<m;j++){
      if(value[i][j]==0){
         if(i-1>=0 && value[i-1][j]>0)s.insert(value[i-1][j]);
         if(i+1<n && value[i+1][j]>0)s.insert(value[i+1][j]);
         ans++;
      }else{
        s.insert(value[i][j]);
      }
    }
    for(auto i:s){
        ans+=(cntvalues[i]);
    }
    result = max(result , ans);
 }
 
  for(int i=0;i<m;i++){
    set<int>s;int ans = 0;
    for(int j=0;j<n;j++){
      if(value[j][i]==0){
         ans++;
          if(i-1>=0 && value[j][i-1]>0)s.insert(value[j][i-1]);
          if(i+1<m && value[j][i+1]>0)s.insert(value[j][i+1]);
      }else{
        s.insert(value[j][i]);
      }
    }
    for(auto i:s){
        ans+=(cntvalues[i]);
    }
    result = max(result , ans);
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