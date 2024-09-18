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
 void setIO(string s1 , string s2) {
	freopen((s1 + ".txt").c_str(), "r", stdin);
	freopen((s2 + ".txt").c_str(), "w", stdout);
}
const int N = 201;
int dp[N][N*N+10][3];
void solve(){
    int n;cin>>n;
    vector<int>arr(n);
    int a , b;cin>>a>>b;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=N*N;j++){
            for(int k=0;k<=2;k++)dp[i][j][k] = 1e9;
        }
    }
    int sum = arr[0];
    int cnt = 0;
    dp[0][arr[0]][1] = (a>=arr[0]?0:1e9);
    dp[0][0][0] = (b>=arr[0]?0:1e9);
    for(int i=1;i<n;i++){
       for(int j=0;j<=a;j++){
           for(int k=0;k<=1;k++){
              if(j+arr[i]<=a && dp[i-1][j][k]!=1e9){
                dp[i][j+arr[i]][1] = min(dp[i][j+arr[i]][1] , dp[i-1][j][k] + (k==0?min(arr[i] , arr[i-1]):0)); 
              }
              if(sum-j+arr[i]<=b && dp[i-1][j][k]!=1e9){
                dp[i][j][0] = min(dp[i][j][0] , dp[i-1][j][k] + (k==1?min(arr[i] , arr[i-1]):0));
              }
                
           }
       } 
       sum+=arr[i];  
       if(sum<=a){
         dp[i][sum][1] = 0;
       }
       if(sum<=b){
         dp[i][0][0] = 0;
       }
       
    }
    int ans = 1e9;
 
    for(int i=0;i<=a;i++){
       
       ans = min(ans , dp[n-1][i][0]);
       ans = min(ans , dp[n-1][i][1]);
    }
    if(ans>=1e9){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
setIO("input" , "output");
int t=1;
while(t--){
solve();
}
}