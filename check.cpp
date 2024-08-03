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
class Solution {
public:
    int part[501][501];
    int dist[501][501];
    int vis[501][501];
    
    bool istrue(int i , int j , int  n , int m , vector<vector<int>>&arr){
        return i>=0 && j>=0 && i<n && j< m && arr[i][j];
    }

    int dfs(int i , int j , vector<vector<int>>&grid){
       cout<<i<<" "<<j<<endl;
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        vector<int>dir = {-1 , 1};
        dist[i][j] = 1;
                for(auto k: dir ){
                    if(istrue(i+k , j , n , m , grid ) && !vis[i+k][j]){
                    dist[i][j] +=   dfs(i+k , j , grid);
                    }
                    if(istrue( i , j+k , n , m , grid) && !vis[i][j+k]){
                       dist[i][j] +=  dfs(i , j+k , grid);
                    }
             }
            return dist[i][j];
    }

    int largestIsland(vector<vector<int>>& grid) {
       cout<<"HELLO"<<endl;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j])dfs(i , j , grid);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max( ans , dist[i][j]);
            }
        }
        return ans;
    }
};



#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
  int n , m;cin>>n>>m;
  vector<vector<int>>grid(n , vector<int>(m));
  for(int i = 0;i<n;i++){
    for(int j=0;j<m;j++)cin>>grid[i][j];
  } 
  debug(grid)
  Solution s;
  int ans = s.largestIsland(grid);
  cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}