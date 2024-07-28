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
void solve(){
   int n;cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   vector<int>pos;
   for(int i=0;i<n;i++){
    if(arr[i]==1){
        pos.push_back(i);
    }
   }
   int k = pos.size();
   vector<vector<int>>dp(n+1 , vector<int>(k+1  , INT_MAX));
   dp[0][0] = 0;
   for(int i=0;i<n;i++){
     for(int j=0;j<=k;j++){
        if(dp[i][j]==INT_MAX)continue;
        dp[i+1][j] = min( dp[i+1][j] , dp[i][j] );
        if(j<k && arr[i]==0){
            dp[i+1][j+1] = min(dp[i+1][j+1] , dp[i][j] + abs(i-pos[j]));
        }
     }
   }
    cout<<dp[n][k]<<endl;
  
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}