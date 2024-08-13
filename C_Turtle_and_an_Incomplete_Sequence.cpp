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

ll cal(ll fele , ll sele){
   map<ll,ll>ans;
   int cnt = 0;
   while(fele>0){
     ans[fele] = cnt;
     cnt++;
     fele/=2;
   }
   cnt = 0;
   while(sele>0){
     if(ans[sele]>0){
       return sele;
     }
     ans[sele] = cnt++;
     sele/=2;
   }
   return 0;
}

void yeh_bhi_krr_lete_hain(){
  ll n;cin>>n;
  ll arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  int suff[n];  
  int next = n;
  bool f = 1;
  for(int i = n-1;i>=0;i--)
  {
     suff[i] = next;
     if(arr[i]!=-1)next = i;
  }
  vector<ll>ans(n,-1);
  int i = 0;
  for( i=0;i<n;i++){
     if(arr[i]!=-1){
        break;
     }
  }
  if(i==n){
    int now[2] = {1 , 2};
    int cnt = 0;
   for(int i=0;i<n;i++){
      cout<<now[i%2]<<" ";
   }cout<<endl;
   return;
  }else{
    int cnt = arr[i];
    int now = 0;
     for(int j=i;j>=0;j--)
     {
       ans[j] = cnt;
       if(now%2==0) cnt*=2;
       else cnt/=2;
     }
  }
  int j;
  for( j = i;j<n;j++){
    if(suff[i]==n){
      break;
    }
    int lca = cal(arr[i] , arr[suff[i]]);
    int next = suff[i];
    int cnt = arr[i];

    while(j<next || cnt>lca){
      ans[j++] = cnt;
      cnt/=2;
    }
    int k = next;
    cnt = arr[next];
    while(k>j || cnt > lca){
       ans[k--] = cnt;
       cnt/=2;
    }
  }
  bool mul = 1;
  int cnt = arr[j-1];
  while(j<n){
      ans[j++] = cnt;
    if(mul){
      cnt*=2;
      mul = 0;
    }else{
      cnt/=2;
      mul = 1;
    }
  }
  if(f){
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
  }else{
     cout<<-1<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
yeh_bhi_krr_lete_hain();
}
}