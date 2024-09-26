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
int cal(string &a , string &b)
{
   int cnt = 0;
   for(int i=0;i<8;i++){
     if(a[i]=='0' && b[i]=='1'){cnt++;}
     if(a[i]=='1' && b[i]=='0'){return INT_MAX;}
   }
   return cnt;
}
void solve(){
 int n;int k;cin>>n>>k;
 vector<string>arr(n+1);
 for(int i=1;i<=n;i++)cin>>arr[i];
 vector<string>check(10);
 for(int i=0;i<10;i++){
    for(int j=0;j<7;j++)check[i]+='0';
 }
 for(int i=1;i<=8;i++){
    check[8][i-1] = '1';
     if(i!=4)
    check[0][i-1]='1';
    if(i==3 || i==6){
        check[1][i-1] = '1';
    }
    if(i==1 || i==3  || i==6){
       check[7][i-1] = '1';
    }
    if(i==1 || i==3 || i==4 || i==5 || i==7){
        check[2][i-1] = '1';
    }
    if(i==2 || i==5){
        check[3][i-1] = '0';
    }else check[3][i-1] = '1';
    if(i==1 || i==5 || i==7){
        check[4][i-1] = '0';
    }else{
        check[4][i-1] = '1';
    }
    if(i==3 || i==5){
        check[5][i-1] = '0';
    }else{
        check[5][i-1] = '1';
    }
    if(i!=3){
        check[6][i-1] = '1';
    }
    if(i!=5){
        check[9][i-1] = '1';
    }
 }
 int dp[n+1][10];
 for(int i=1;i<=n;i++){
    for(int j=0;j<=9;j++){
       dp[i][j] = cal(arr[i] , check[j]);
    }
 }
  
 
  
  vector<vector<int>>f(n+2 , vector<int>(k+1 , 0));
  f[n+1][0] = 1;
  for(int i=n;i>=1;i--){
   
    for(int j=0;j<=k;j++){
       if(f[i+1][j]){
            for(int l=0;l<=9;l++){
                if (dp[i][l] != INT_MAX && j + dp[i][l] <= k) {
                    f[i][j + dp[i][l]] = 1;
                }
            }
       }
    }
  }
   if(f[1][k]==0){
     cout<<-1<<endl;return;
   }
    
   for(int i=1;i<=n;i++){
     char now = '-1';
     for(int j=9;j>=0;j--){
       if(dp[i][j]<=k && f[i+1][k-dp[i][j]]){
          now = '0'+j;
          k-=dp[i][j];
          break;
       }  
     } 
     cout<<now;
   }
cout<<endl;

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}