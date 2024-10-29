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
class matrix{
 public:
 vector<vector<ll>>arr;
 matrix(){
    arr.resize(2 , vector<ll>(2 , 0));
 } 
};

matrix product(matrix &a , matrix &b){
  matrix ans;
  for(int i=0;i<2;i++)
  {
     for(int j=0;j<2;j++){
        for(int k=0;k<2;k++)
           (ans.arr[i][j]+=((a.arr[i][k])*(b.arr[k][j])))%=mod;  
     }
  }  
  return ans;
}
class segment{
  public:
  vector<matrix>tree;
  int n ;
  segment(ll n){
     this->n = n;
     tree.resize(4*n+4);
  }
  matrix build(vector<matrix>&arr , int l , int r , int ind)
  {
     if(l==r){return tree[ind] = arr[l];}
     int mid = (l+r)/2;
     matrix  left = build(arr , l , mid , 2*ind+1);
     matrix right = build(arr , mid+1 , r , 2*ind+2);
     return tree[ind] = product(left , right);
  }
  matrix query(int l , int r , int a , int b , int ind)
  { 
    if(l>b || r<a){
      matrix now;now.arr[0][0] = 1;now.arr[1][1] = 1;
      return now;
    } 
    if(l>=a && r<=b){return tree[ind];}
    int mid = (l+r)/2;
    matrix left = query(l , mid , a , b , 2*ind+1);
    matrix right = query(mid +1 , r , a , b , 2*ind+2);
    return product(left , right);
  }
};



void solve(){
 int n , m;cin>>mod>>n>>m;
 vector<matrix>a(n);
 for(int i=0;i<n;i++){
    for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
            cin>>a[i].arr[j][k];
        }
    }
 }
  segment t(n+1);
  t.build(a , 0 , n-1 , 0);
 
  while(m--)
  {
    int l , r;cin>>l>>r;
    l--;r--;
    matrix ans = t.query(0 , n-1 , l , r , 0);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<(ans.arr[i][j])<<" ";
        }cout<<endl;
    }cout<<endl;
  }

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}