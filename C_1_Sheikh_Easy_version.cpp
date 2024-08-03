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
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
 ll n;cin>>n;int q;cin>>q;
 vector<ll>arr(n+1);vector<ll>prefix(n+1 , 0);
 vector<ll>xr(n+1,0);
 for(int i=1;i<=n;i++)cin>>arr[i];
 for(int i=1;i<=n;i++){
     prefix[i] = prefix[i-1]  + arr[i];
     xr[i] = xr[i-1]^arr[i];
 }
  int l , r;cin>>l>>r;
   int left =  l , right = l;
   int ansl =l , ansr = r;
   ll ans = prefix[r] - prefix[l-1] - (xr[r]^xr[l-1]);
   for( left = l ;left<=r;left++){
       if(left>right)right = left;
       while(right <=r && ((prefix[right] - prefix[left-1]) - (xr[right]^xr[left-1]) )< ans )right++;
       if(right>r){
        break;
       }    
      if(right<=r && (right - left)<(ansr - ansl)){
        ansl = left , ansr = right;
      }
   }
    cout<<ansl<<" "<<ansr<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}