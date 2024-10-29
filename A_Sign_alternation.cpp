// Don't look the rank , if you want a good rank
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
//flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
 
class segment{
  vector<ll>tree;
  int n ;
  public:
  segment(ll n){
     this->n = n;
     tree.assign(4*n+4 , 0);
  }
  ll build(vector<ll>&arr , int l , int r , int ind)
  {
     if(l==r){return tree[ind] = arr[l];}
     ll mid = (l+r)/2;
     ll left = build(arr , l , mid , 2*ind+1);
     ll right = build(arr , mid+1 , r , 2*ind+2);
     if((mid - l + 1)%2){
       return tree[ind] = (left - right);
     }else{
       return tree[ind] = (left + right);
     }
  }
   ll query(int l , int r , int a , int b , int ind)
  { 
    if(l>b || r<a){ return LLONG_MAX;} 
    if(l>=a && r<=b){return tree[ind];}
    int mid = (l+r)/2;
    ll left = query(l , mid , a , b , 2*ind+1);
    ll right = query(mid +1 , r , a , b , 2*ind+2);
    
    if(left==LLONG_MAX){
       return right;
    }else if(right==LLONG_MAX){
       return left;
    }
    int leftarc = max(a , l);
     
    leftarc = mid - leftarc + 1;
    if(leftarc%2){
        return left - right;
    }
    return left + right;
  }
  ll update(int l ,int r , int i , int ind , int val)
  {
      if(l>i || r<i){return tree[ind];}
      if(l==r && l==i){
         return tree[ind] = val;
      }
      int mid = (l+r)/2;
      ll left = update(l , mid , i , 2*ind+1 , val);
      ll right = update(mid+1 ,r , i , 2*ind+2 , val);
      if((mid - l + 1)%2){
       return tree[ind] = (left - right);
     }else{
       return tree[ind] = (left + right);
     }
  }
};

void solve(){
  int n;cin>>n;
  vector<ll>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  segment t(n+1);
  t.build(arr , 0 , n-1 , 0);
    
   int m;cin>>m;
   while(m--)
   {
    int type;cin>>type;
    if(type==1){
         int l ,r ;cin>>l>>r;
         l--;r--;
         cout<<t.query(0 , n-1 , l , r , 0)<<endl;
    }else{
         int i , j;cin>>i>>j;i--;
         t.update(0 , n-1 , i , 0 , j);
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