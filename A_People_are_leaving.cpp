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
class Dsu{
  public:
 Dsu(int x){
     rank = new int[x+1];
     parent = new int[x+1];
     ans = new int[x+1];
     for(int i = 0;i<=x;i++)rank[i] = 0;
     for(int i = 0;i<=x;i++)parent[i] = i,ans[i] = i;
 }
 int* rank;
 int*parent;
 int*ans;
 int find(int a){
    if(parent[a]==a)return a;
    return find(parent[a]);
 }
 bool same(int a , int b){
    return find(a)==find(b);
 }
 
 int Draw_edge(int a , int n){
     int parenta = find(a);
     int now = ans[parenta];
     int parentb = find(now%n+1);
     if(rank[parenta]>rank[parentb]){
        parent[parentb] = parenta;
        ans[parenta] =  ans[parentb];
     }else if(rank[parentb]> rank[parenta]){
        parent[parenta] = parentb;
     }
     else{
        parent[parentb] = parenta;
        rank[parenta]++;
        ans[parenta] =  ans[parentb];
     }
     return now;
 }
 
};



void solve(){
 int n;cin>>n; 
 Dsu tree(n+2);
 vector<int>arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 for(int i=0;i<n;i++){
    int now = tree.Draw_edge(arr[i] , n);
    cout<<now<<" ";
 }
 

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}