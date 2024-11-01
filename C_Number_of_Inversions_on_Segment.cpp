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
// template<class T> ll cal(vector<T>&a , int la , int lb , int rl , int rr , int n );

class segment{
  public:
  vector<ll>tree;
  int n ;
  segment(ll n){
     this->n = n;
     tree.assign(4*n+4 , 0);
  }
    ll cal(vector<segment>&a , vector<segment>&count , int la , int lb , int rl , int rr , int n ){
        ll ans = 0;
        for(int i=1;i<=40;i++){
        ll cnti = count[i].query(0 , n-1 , rl , rr , 0);
         // for(int j=i+1;j<=40;j++)
           ans+=(cnti*a[i].query(0 , n-1 , la , lb , 0));
        }
        return ans;
    }
  ll build(vector<ll>&arr , int l , int r , int ind)
  {
     if(l==r){return tree[ind] = arr[l];}
     int mid = (l+r)/2;
     int left = build(arr , l , mid , 2*ind+1);
     int right = build(arr , mid+1 , r , 2*ind+2);
     return tree[ind] = (left + right);
  }
  ll query(int l , int r , int a , int b , int ind)
  { 
    if(l>b || r<a){return 0;} 
    if(l>=a && r<=b){return tree[ind];}
    int mid = (l+r)/2;
    int left = query(l , mid , a , b , 2*ind+1);
    int right = query(mid +1 , r , a , b , 2*ind+2);
    return (left + right);
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
      return tree[ind] =  (left + right);
  }

  ll build(vector<ll>&arr , int l , int r , int ind , vector<segment>&a ,vector<segment>&count , int N)
  {
     if(l==r){return tree[ind] = 0;}
     int mid = (l+r)/2;
    
     ll left = build(arr , l , mid , 2*ind+1 , a , count , N);
     ll right = build(arr , mid+1 , r , 2*ind+2 , a , count , N);
     return tree[ind] = left + right + cal(a , count ,  l , mid , mid+1 , r , N);
  }

  ll query(int l , int r , int a , int b , int ind , vector<segment>&arr ,vector<segment>&count , int N )
  { 
    if(l>b || r<a){return LLONG_MAX;} 
    if(l>=a && r<=b){return tree[ind];}
    int mid = (l+r)/2;
    ll left = query(l , mid , a , b , 2*ind+1 , arr , count ,  N);
    ll right = query(mid +1 , r , a , b , 2*ind+2 , arr , count , N);
    if(right==LLONG_MAX){
        return left;
    }else if(left==LLONG_MAX){
        return right;   
    }
    return left + right + cal(arr , count , max(a , l) , mid , mid+1 ,min( r  , b), N);
  }
  ll update(int l ,int r , int i , int ind , vector<segment>&arr ,vector<segment>&count ,  int N)
  {
      if(l>i || r<i){return tree[ind];}
      if(l==r && l==i){
         return tree[ind] = 0;
      }
      int mid = (l+r)/2;
      ll left = update(l , mid , i , 2*ind+1 , arr , count , N);
      ll right = update(mid+1 ,r , i , 2*ind+2 , arr ,count ,  N);    
      tree[ind] =  (left + right + cal(arr , count , l , mid , mid +1 , r ,  N));
      return tree[ind];
  }
};

 




void solve(){
  int n , q;cin>>n>>q;
  vector<ll>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  vector<segment>t(41 , segment(n+1));
  vector<segment>count(41 , segment(n+1));
  for(int i=1;i<=40;i++){
    vector<ll>temp;vector<ll>cnt;
     for(int j=0;j<n;j++){
        if(arr[j]>i){temp.push_back(1);}
        else temp.push_back(0);
        if(arr[j]==i){
         cnt.push_back(1);
        }else cnt.push_back(0);
     }
      
     t[i].build(temp , 0 , n-1 , 0);
     count[i].build(cnt , 0 ,n-1 , 0);
  }
 
  segment a(n+1);
  a.build(arr , 0 ,n-1 , 0 , t , count , n);
  
 
  while(q--)
  {
     int type;cin>>type;
     if(type==1)
     {
        int l , r;cin>>l>>r;
        l--;r--;
        cout<<a.query(0 , n-1 , l , r , 0 , t , count ,  n)<<endl;  
        
     }else{
        ll l , val;cin>>l>>val;l--;
        for(int i = min(arr[l] , val);i<max(arr[l] , val);i++){
            t[i].update(0 , n-1 , l , 0 , arr[l]<val); 
        }
        count[arr[l]].update(0 , n-1 , l , 0 , 0);
        arr[l] = val;
        count[arr[l]].update(0 , n-1 , l , 0 , 1);
        a.update(0 , n-1 , l , 0 , t , count ,  n);
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