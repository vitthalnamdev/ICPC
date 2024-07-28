#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
bool istrue(int i , int j , int n , int m ){
  return i>=0 && j>=0 && i<n && j<m;
}
ll dp[505][505][30];
const ll INF = 1e15;
ll  cal(int i , int j , int len ,   int n , int m 
, vector<vector<ll>>&Row , 
vector<vector<ll>>&Col){
  
  if(dp[i][j][len]!=INF){return dp[i][j][len];}
  if(len==0)return 0LL;
  vector<int>dir = { -1 , 1};
  ll curr = INF;
  for(auto k: dir ){
    if(istrue(i+k , j , n , m))
    curr = min( curr , Row[i + (k==-1? -1:0)][j] + cal(i+k , j , len-1 ,  n , m , Row , Col));
    if(istrue(i , j+k , n , m ))
    curr = min(curr , Col[i][j + (k==-1? -1 : 0)] + cal(i , j+k , len - 1 ,   n , m , Row , Col));
  }
  return dp[i][j][len] = curr;
}
void solve(){
  int n,m,k;cin>>n>>m>>k;
  vector<vector<ll>>Col(n , vector<ll>(m-1));
  for(int i=0;i<n;i++){
    for(int j=0;j<m-1;j++){
       cin>>Col[i][j];
    }
  }
  vector<vector<ll>>Row(n-1 , vector<ll>(m));
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m;j++){
        cin>>Row[i][j];
    }
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
        for(int k=0;k<=20;k++)dp[i][j][k] = INF;
    }
  }
  vector<vector<ll>>ans(n , vector<ll>(m , -1 ));
   
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(k%2){continue;}
      ll curr = cal(  i , j , k/2,   n , m , Row , Col  );
       
      ans[i][j] = 2*curr;
    }
 }
 
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<ans[i][j]<<" ";
    }cout<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}