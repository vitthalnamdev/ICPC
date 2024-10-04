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
pair<ll,ll>mini(pair<ll,ll>a , pair<ll,ll>b)
{
    if(a.first==b.first){
       return {a.first , a.second + b.second};
    }
    if(a.first<b.first){
      return a;
    }else{
       return b;
    }
}


class segment{
  int n ;
  public:

  vector<pair<ll,ll>>tree;
  segment(ll n){
     this->n = n;
     tree.assign(4*n+4 , {INT_MAX , 1});
  }

  pair<ll,ll> build(vector<ll>&arr , int l , int r , int ind)
  {
     if(l==r){return tree[ind] = make_pair(arr[l] , 1);}
     int mid = (l+r)/2;
     auto left = build(arr , l , mid , 2*ind+1);
     auto right = build(arr , mid+1 , r , 2*ind+2);  
     return tree[ind] = mini(left , right);
  }

  pair<ll,ll> query(int l , int r , int a , int b , int ind)
  { 
    if(l>b || r<a){return {INT_MAX , 0};} 
    if(l>=a && r<=b){return tree[ind];}
    int mid = (l+r)/2;
    auto left = query(l , mid , a , b , 2*ind+1);
    auto right = query(mid +1 , r , a , b , 2*ind+2);
    return mini(left , right);
  }

  pair<ll,ll> update(int l ,int r , int i , int ind , int val)
  {
      if(l>i || r<i){return tree[ind];}
      if(l==r && l==i){
         return tree[ind] = {val , 1};
      }
      int mid = (l+r)/2;
      auto  left =  update(l , mid , i , 2*ind+1 , val);
      auto  right = update(mid+1 ,r , i , 2*ind+2 , val);     
      return tree[ind] = mini(left , right);
  }
};

void solve(){
 int n, m;cin>>n>>m;
 vector<ll>arr(n);
 for(int i=0;i<n;i++)cin>>arr[i];
 segment tree(n+1);
 tree.build(arr , 0 , n-1 , 0);
 while(m--)
 {
    int a , l , r;cin>>a>>l>>r;
    if(a==1){
        tree.update(0 , n-1 , l , 0 , r);
    }else{
        auto ans = tree.query(0,n-1 ,l , r-1 , 0);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
 }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}