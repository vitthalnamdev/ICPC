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

class suffix_array{
  public:
  string s;
  vector<pair<char,int>>p;
  vector<pair<pair<int,int>,int>>mapvalue;
  vector<int>c;
  int n;
  suffix_array(string val)
  {
    s = val;
    n = s.length();
    p.resize(n);
    c.resize(n);
    mapvalue.resize(n);
  }
   
  void build(){
    
    for(int i=0;i<n;i++){
        p[i] = {s[i] , i};
    }
     sort(p.begin(),p.end());
     c[0] = 0;
     for(int i=1;i<n;i++){
         if(p[i].first==p[i-1].first){
             c[p[i].second] = c[p[i-1].second];
         }else{
             c[p[i].second] = c[p[i-1].second] + 1;
         }
     } 
  }


   void complete_build(){
       int k = 0;
       int cnt = 0;
       int last=0;
       for(int i=0;i<32;i++){
          if((n&(1<<i)))
          {
            cnt++;last = i;
          }
       }
       int factor;
       if(cnt>1){
          factor = (1<<(last+1));
       }else{
          factor = (1<<last);
       }
         
        for(int i=0;i<n;i++){
            mapvalue[i].second = p[i].second;
        }
       while((1<<k) <= factor){
           for(int i=0;i<n;i++){
             mapvalue[i].first = {c[mapvalue[i].second] , c[(mapvalue[i].second + (1<<k))%n]};   
             mapvalue[i].second = mapvalue[i].second;
           }
         sort(mapvalue.begin(),mapvalue.end());
        for(int i=1;i<n;i++){
            if(mapvalue[i].first==mapvalue[i-1].first){
                c[mapvalue[i].second] = c[mapvalue[i-1].second];
            }else{
                c[mapvalue[i].second] = c[mapvalue[i-1].second] + 1;
            }
         } 
          
         k++;
       }
        for(int i=0;i<n;i++){
            cout<<mapvalue[i].second<<" ";
        }
   }

};













void solve(){
   string s;cin>>s;
   s+='$';
    
   suffix_array check = suffix_array(s);

   check.build();
   check.complete_build();
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}