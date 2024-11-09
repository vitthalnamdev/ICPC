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
  ll prev = -1;
  int n ;
  public:
  segment(ll n){
    this->n = n;
    tree.assign(4*n+4 , prev);
  }

  int operation(int a , int ele){
    if(ele==prev){return a;}
    return ele;
  }

  void propagate(int ind , int l , int r ){
     if(l==r){
        return;
     }
     tree[2*ind + 1] = operation(tree[2*ind+1] ,tree[ind]);
     tree[2*ind + 2] = operation(tree[2*ind+2] , tree[ind]);
     tree[ind] = prev;
  }

  void rangeupdate(int l ,int r , int a , int b , int val , int ind){
     propagate(ind , l , r);
     if(l>b || r<a){return;}
     if(l>=a && r<=b){
        tree[ind]=operation(tree[ind] , (ll)val);
        return;
     }
     if(l==r){
        tree[ind]=operation(tree[ind] , (ll)val);
        return;
     }
     int mid = (l+r)/2;
     rangeupdate(l , mid , a , b , val , 2*ind + 1);
     rangeupdate(mid+1 , r , a , b , val , 2*ind + 2);
  }
 
  ll rangequery(int l , int r , int i, int ind){
     if(l>i || r<i){return prev;}
     if(l==r){
        return tree[ind];
     }
     int mid = (l + r)/2;
     ll res = tree[ind];
     res = operation(rangequery(l , mid , i , 2*ind + 1) , res) ,
     res = operation(rangequery(mid+1 , r , i, 2*ind + 2) , res);
     return res;
  }
 
};


void solve(){
   int n;cin>>n;int m;cin>>m;
   segment t(n+1);
   while(m--)
   {
     int type;cin>>type;
     if(type==1){
        int l , r , val;cin>>l>>r>>val;
        t.rangeupdate(0 , n-1 , l , r-1 , val , 0);
     }else{
        int x;cin>>x;
        ll ans = t.rangequery(0 , n-1 , x , 0);
        if(ans==-1){
            cout<<0<<endl;continue;
        }
        cout<<ans<<endl;
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