#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
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
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
 int n;cin>>n;
 ll arr[n];
 for(int i=0;i<n;i++)cin>>arr[i];
 ll brr[n];
 for(int i=0;i<n;i++){
    brr[i] = -arr[i];
 }
 int ind = 0;
 ll sum = 0;ll mx = 0;bool f= 1;
 for(int i=0;i<n;i++){
    sum+=brr[i];
     
    if(sum>mx){
        mx = sum;
        if(f){
            ind = i;
            f=0;
        }
    }
    if(sum<0){
      sum = 0;
      f=1;
    }
 }
 debug(mx)
 debug(ind)
 ll ans = 0;
 ll curr = 0;
 for(int i=0;i<ind;i++){
    curr+=arr[i];
    ans = max(ans , curr);
 }

 cout<<ans<<endl;
 
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}