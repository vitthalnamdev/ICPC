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
     rank2 = new int[x+1];
     parent2 = new int[x+1];
     for(int i = 0;i<=x;i++)rank[i] = 0 , rank2[i] = 0;
     for(int i = 0;i<=x;i++)parent[i] = i , ans[i] = i , parent2[i] = i;
 }
 int* rank;
 int*parent;
 int*ans;
 int*parent2;
 int*rank2;
 int find(int a){
    if(parent[a]==a)return a;
    return find(parent[a]);
 }

 bool same(int a , int b){
    return find(a)==find(b);
 }
 
 int Draw_edge(int a, int b){
     int parenta = find(a);
     int parentb = find(b);
     if(parenta==parentb){return false;}
     
     Draw_edge2(parenta , parentb);
     if(rank[parenta]>rank[parentb]){
        parent[parentb] = parenta;
        ans[parenta] = ans[parentb];
        return ans[parenta];
     }else if(rank[parentb]> rank[parenta]){
        parent[parenta] = parentb;
        return ans[parentb];
     }
     else{
        parent[parentb] = parenta;
        ans[parenta] = ans[parentb];
        rank[parenta]++;
        return ans[parenta];
     }
     return -1;
 }
  int find2(int a){
    if(parent2[a]==a)return a;
    return find2(parent2[a]);
 }
 bool Draw_edge2(int a , int b){
    int parenta = find2(a);
     int parentb = find2(b);
 
     if(parenta==parentb){return false;}
     
     if(rank2[parenta]>rank2[parentb]){
        parent2[parentb] = parenta;
     }else if(rank2[parentb]> rank2[parenta]){
        parent2[parenta] = parentb;
     }
     else{
        parent2[parentb] = parenta;
        
        rank2[parenta]++;
        
     }
     return true;
 }
};  
 

void solve(){
 int n;cin>>n;
 int q;cin>>q;
 Dsu tree(n+1);
 while(q--)
 {
     int opt;int l , r;cin>>opt>>l>>r;
      if (opt == 1) {
            tree.Draw_edge2(l, r);
        } else if (opt == 2) {
            for (int i = tree.ans[tree.find(l)]; i < r; i = tree.ans[tree.find(i + 1)]) {
                tree.Draw_edge(i, i + 1);
            }
        } else {
             
            int fx = tree.find(l);int fy = tree.find(r);
            fx = tree.find2(fx);fy = tree.find2(fy);
            if(fx==fy){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
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