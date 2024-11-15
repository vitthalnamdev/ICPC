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
void dfs(int node , int parent , vector<int>adj[] , vector<int>&odd , vector<int>&even)
{
    for(auto i:adj[node])
    {
        if(i==parent){continue;}
        dfs(i , node , adj , odd , even);
        even[node] += odd[i];
        odd[node] += (even[i]+1);
    }
}

ll ans = 0;
void reroot(int node , int parent , vector<int>adj[] , vector<int>&even  , vector<int>&odd , int oddtot , int eventot){
    ans+=oddtot;
    
   for(auto i:adj[node])
   {
     if(i==parent)continue;
         int lrfteven = eventot - odd[i];
         int lefto = oddtot - (even[i]+1);
         
         
        int neweven = lefto + even[i];
        int newodd = odd[i] + (lrfteven+1);
     
        
        reroot(i , node , adj , even , odd , newodd , neweven);
   }
}


void solve(){
    ans = 0;
 ll n;cin>>n;
 vector<int>adj[n+1];
 for(int i=1;i<n;i++){
    int a , b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
 }
 vector<int>odd(n+1 , 0) , even(n+1 , 0);
 dfs(1 , -1 , adj , odd , even);
  
 reroot(1 , -1 , adj , even , odd , odd[1] , even[1]); 
 
 ans/=2;
 ll result =  (n*(n-1))/2;
 
result-=ans;
cout<<result<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}