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
 
void solve(){
  int n;cin>>n;
   vector<vector<int>>points(n , vector<int>(5 , 0));
  for(int i=0;i<n;i++){
     cin>>points[i][0]>>points[i][1]>>points[i][2]>>points[i][3];
     points[i][4] = i;
  }

    
  sort(points.begin() , points.end() , [](const vector<int>&a , const vector<int>&b){
    return a[3]<b[3];
  });
  

  vector<int>ans(n);
  int mn = INT_MAX;int mnind = n-1;
  for(int i=n-1;i>=0;i--)
  {
    if(i==n-1){
        ans[points[i][4]] = points[i][3];
    }else if(points[i][3]<mn){
        ans[points[i][4]] = points[i][3];
    }else{
        ans[points[i][4]] = ans[points[mnind][4]];
    }
    if(points[i][0]<mn){
        mn = points[i][0];
        mnind = i;
    }
  }
  
  sort(points.begin() , points.end() , [](const vector<int>&a , const vector<int>&b){
    return a[0]<b[0];
  });
  int q;cin>>q;
  
  while(q--)
  {
     int x;cin>>x;
      auto ind = upper_bound(points.begin(), points.end(), x, [](int value, const vector<int>& point) {
        return value < point[0];
    })- points.begin();
       
     if(ind==0){
        cout<<x<<" ";
     }else{
        cout<<max(x , ans[points[ind-1][4]])<<" ";
     }
  }cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}