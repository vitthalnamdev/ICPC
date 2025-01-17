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
class Dsu{
  public:
 Dsu(int x){
     rank = new int[x+1];
     parent = new int[x+1];
     for(int i = 0;i<=x;i++)rank[i] = 0;
     for(int i = 0;i<=x;i++)parent[i] = i;
 }
 int* rank;
 int*parent;
 
 int find(int a){
    if(parent[a]==a)return a;
    return find(parent[a]);
 }
 bool same(int a , int b){
    return find(a)==find(b);
 }
 
 bool Draw_edge(int a, int b){
     int parenta = find(a);
     int parentb = find(b);
 
     if(parenta==parentb){return false;}
     
     if(rank[parenta]>rank[parentb]){
        parent[parentb] = parenta;
     }else if(rank[parentb]> rank[parenta]){
        parent[parenta] = parentb;
     }
     else{
        parent[parentb] = parenta;
        rank[parenta]++;
     }
 
     return true;
 }
 
};

void solve(){

    int n , m , k;cin>>n>>m>>k;
    set<pair<int,int>>s;
    for(int i=0;i<m;i++){
       int a, b;cin>>a>>b;
       s.insert({min(a , b) ,max(a , b)});
    }
    vector<vector<int>>query;
    for(int i =0 ;i< k ;i++){
       string check;cin>>check;
       int a , b;cin>>a>>b;
       query.push_back({check=="cut" , min(a , b) , max(a , b)});
       if(check=="cut"){
         s.erase(s.find({min(a , b) , max(a , b)}));
       }
    }
     
    Dsu temp(n+1);
    for(auto i:s){
       temp.Draw_edge(i.first , i.second);
    }
    vector<string>result;
    for(int i=k-1;i>=0;i--)
    {
      
       if(query[i][0]==1){
          temp.Draw_edge(query[i][1] , query[i][2]); 
       }else{
         
          int ans = temp.same(query[i][1] , query[i][2]);
          if(ans){
//            cout<<"YES"<<endl;
               result.push_back("YES");
          }else{
            // cout<<"NO"<<endl;
            result.push_back("NO");
          }
       }
    }
    reverse(result.begin() , result.end());
    for(auto i:result)cout<<i<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
// int t;cin>>t;
int t= 1;
while(t--){
solve();
}
}
// It was a easy problem , I am just solving a harder problem. 
// Just try to think in a different way. 