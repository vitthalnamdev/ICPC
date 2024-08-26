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

pair<ll,ll>maxi(pair<ll,ll>a , ll b , ll ind , vector<ll>&arr)
{
    if(a.first==b){
        if(arr[a.second] > arr[ind]){
          pair<int,int>ans = {b , ind};
          return ans;
        }
        return a;
    }
    if(a.first>b){
        return a;
    }
    pair<ll,ll>ans = {b , ind};
    return ans;
}


vector<ll>mini(vector<ll>&a , vector<ll>&b , vector<ll>&arr){
    for(int i=0;i<a.size();i++){
       if(arr[a[i]]>arr[b[i]]){
        return b;
       }else if(arr[a[i]]<arr[b[i]]){
         return a;
       }
    }
    return a;
}

vector<ll>path(vector<vector<pair<ll,ll>>>&dp , int ind , int k){
  vector<ll>ans;
  while(ind!=-1)
  {
    ans.push_back(ind);
    ind = dp[ind][k--].second;
  }
  reverse(ans.begin(),ans.end());
  return ans;  
}

void solve(){
 int n;cin>>n;
 vector<ll>arr(n);
 for(int i=0;i<n;i++)cin>>arr[i];
 int m;cin>>m;
    vector<vector<pair<ll,ll>>>dp(n+1 , vector<pair<ll,ll>>(n+1,{0,-1}));
    for(int i=1;i<=n;i++){
      for(int j=i-1;j<n;j++){
           if(i==1){
              dp[j][i] = {arr[j] , -1}; 
              continue;
           }
        for(int k=0;k<j;k++){
           dp[j][i] = maxi(dp[j][i] , dp[k][i-1].first + arr[j],k , arr);
        }
      }
    }
  // for(int i=0;i<n;i++)cout<<dp[i][3].first<<" "<<dp[i][3].second<<endl;cout<<endl;
 while(m--)
 {
    ll k, pos;cin>>k>>pos;
    ll  check = 0;
    vector<ll>ind;

    for(int i=0;i<n;i++){
        if(dp[i][k].first > check){
            ind.clear();
            check = dp[i][k].first;
            ind.push_back(i);
        
        }else if(dp[i][k].first==check)
        {
            ind.push_back(i);
        }
    }
     
    vector<ll>ans(k+1 , LLONG_MAX);
    for(int i=0;i<ind.size();i++)
    {
        vector<ll>curr =  path(dp , ind[i] , k);
        ans = mini(ans , curr , arr); 
    }
    // for(auto i:ans)cout<<i<<endl;
    cout<<arr[ans[pos-1]]<<endl;
 }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}