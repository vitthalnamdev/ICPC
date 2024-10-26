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
void solve(){
 int n , m;cin>>n>>m;
 vector<int>arr(n+m+1);
 vector<int>brr(n+m+1);
 for(int i=0;i<n+m+1;i++)cin>>arr[i];
 for(int i=0;i<n+m+1;i++)cin>>brr[i];
 set<int>programmers,testers;
 ll ans = 0;
 for(int i=0;i<n+m;i++){
    if(arr[i]>brr[i] && programmers.size()<n){
        programmers.insert(i);
        ans+=arr[i];
    }else if(testers.size()<m){
        testers.insert(i);
        ans+=brr[i];
    }else{
        programmers.insert(i);
        ans+=arr[i];
    }
 }
 int pind=-1;int tind = -1;
 for(int i=n+m;i>=0;i--){
    auto p = programmers.end();
    auto t = testers.end();
    
     if(programmers.size()>=1 && arr[i]>brr[i] && i>*(--p)){
        pind = i;
     }
     if(testers.size()>=1 && brr[i]>arr[i] && i>*(--t)){
        tind = i;
     }
 }
  
 for(int i=0;i<n+m;i++){
    auto f = programmers.find(i);
    ll curr;
    if(f!=programmers.end()){
        curr = ans - arr[i] + (pind==-1?arr[n+m]:arr[pind] - brr[pind] + brr[n+m]);
    }else{
        curr = ans - brr[i] + (tind==-1?brr[n+m]:brr[tind] - arr[tind] + arr[n+m]);
    }
    cout<<curr<<" ";
 }
 cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}