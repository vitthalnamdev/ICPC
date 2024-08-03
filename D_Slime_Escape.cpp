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
  ll n , k;cin>>n>>k;
  k--;
  vector<ll>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int i = k-1;
  int j = k+1;
  ll sum = arr[k];
  while(true){
    ll curr = sum;
    ll id = i;
    ll max1 = sum;
    ll id1 = i;
    while(id>=0 && curr + arr[id]>=0)
    {
        curr+=arr[id];
        id--;
        if(curr>=max1)
        {
          max1 = curr;
         id1 = id;
        }
    }
    if(id<0){
        cout<<"YES"<<endl;return;
    }
    ll currpost = sum;
    ll idpost = j;
    ll maxpost1 = sum;
    ll idpost1 = j;
    while(idpost<n && currpost + arr[idpost]>=0)
    {
        currpost+=arr[idpost];
        idpost++;
        if(currpost>=maxpost1)
        {
         maxpost1 = currpost;
         idpost1 = idpost;
        }
    }
    if(idpost>=n){
        cout<<"YES"<<endl;return;
    }
    if(max1==sum && maxpost1==sum){
        cout<<"NO"<<endl;return;
    }else{
        if(max1>maxpost1){
           i = id1;
           sum = max1;
        }else{
           j = idpost1;
           sum = maxpost1;  
        }
    }
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}