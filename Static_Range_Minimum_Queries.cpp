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

class segment{
  vector<int>tree;
  int n ;
  public:
  segment(ll n){
     this->n = n;
     tree.assign(4*n+4 , INT_MAX);
  }
  int build(vector<ll>&arr , int l , int r , int ind)
  {
     if(l==r){return tree[ind] = arr[l];}
     int mid = (l+r)/2;
     int left = build(arr , l , mid , 2*ind+1);
     int right = build(arr , mid+1 , r , 2*ind+2);
     return tree[ind] = min(left , right);
  }
  int query(int l , int r , int a , int b , int ind)
  { 
    if(l>b || r<a){return INT_MAX;} 
    if(l>=a && r<=b){return tree[ind];}
    int mid = (l+r)/2;
    int left = query(l , mid , a , b , 2*ind+1);
    int right = query(mid +1 , r , a , b , 2*ind+2);
    return min(left , right);
  }
  ll update(int l ,int r , int i , int ind , int val)
  {
      if(l>i || r<i){return tree[ind];}
      if(l==r && l==i){
         return tree[ind] = val;
      }
      int mid = (l+r)/2;
      int left = update(l , mid , i , 2*ind+1 , val);
      int right = update(mid+1 ,r , i , 2*ind+2 , val);
      return tree[ind] = min(left , right);
  }
};

#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
void yeh_bhi_krr_lete_hain(){
  int n , q;cin>>n>>q;
  vector<ll>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  segment seg = segment(n);
  seg.build(arr,0,n-1 , 0);
  while(q--)
  {
       int query;cin>>query;
       if(query==1)
       {
           int ind , x;cin>>ind>>x;
           arr[ind-1] = x;
           seg.update(0, n-1 , ind-1 , 0 , x);
           
       }else{
           int a , b;cin>>a>>b;
           cout<<seg.query(0,n-1 , a-1 , b-1 , 0)<<endl;
       }
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
yeh_bhi_krr_lete_hain();
}
}