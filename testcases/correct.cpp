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
void yeh_bhi_krr_lete_hain(){
 ll n , k;cin>>n>>k;
 ll arr[n];
 for(ll i=0;i<n;i++)cin>>arr[i];
 ll count[51];
 for(ll i=0;i<=50;i++)count[i] = 0;
 for(ll i=0;i<n;i++)
 {
    count[arr[i]]++;
 }
 ll fac[51];
//  ll lac[51];
 for(ll i=0;i<=50;i++){
    fac[i] = -1;
    // lac[i] = -1;
 }
 
 for(ll i=0;i<n;i++)
 {
     if(fac[arr[i]]==-1){
        fac[arr[i]] = i;
     }
    //  lac[arr[i]] = i;
 }
 ll ans = 0;
 for(ll i = 1;i<=50;i++){
     if(count[i]==0){
        continue;
     }
     multiset<ll>s;
  
     ll start = fac[i];
     ll tot = k-2;
     if(n-start-2<tot){continue;}
     ll mx = i;
     for(ll j=start + 1 ;j<n;j++){
          if(tot>0){
            s.insert(arr[j]);
            mx+=(2*arr[j]);
            tot--;
          }else{
            ans = max(ans , mx+arr[j]);
            auto f = s.lower_bound(arr[j]);
            if(f!=s.begin()){
              mx-=(2*(*s.begin()));
              s.erase(s.begin());
              mx+=(2*arr[j]);
              s.insert(arr[j]);
            }
          }
           
     }
   
 }
cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
yeh_bhi_krr_lete_hain();
}
}