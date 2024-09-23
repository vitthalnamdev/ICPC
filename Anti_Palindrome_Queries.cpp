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
void solve(){
 int n , q;cin>>n>>q;
 vector<int>arr(n);
 for(int i=0;i<n;i++)cin>>arr[i];
 vector<int>one(n,0) , two(n,0) , three(n,0);
 for(int i=0;i<n;i++){
    one[i] = (i-1>=0?one[i-1]:0) + (arr[i]==1);
    two[i] = (i-1>=0?two[i-1]:0) + (arr[i]==2);
    three[i] = (i-1>=0?three[i-1]:0) + (arr[i]==3);
 }
 while(q--)
 {
    int l , r;cin>>l>>r;
    int len = r-l+1;
    r--;l--;
    if(len%2){
        cout<<"No"<<endl;continue;
    }
    vector<int>curr(3);
    curr[0] = one[r]-(l-1>=0?one[l-1]:0);
    curr[1] =  two[r]-(l-1>=0?two[l-1]:0);
    curr[2] =  three[r]-(l-1>=0?three[l-1]:0);
    sort(curr.begin() , curr.end());
    int pos = len/2;
    if(curr[2]==pos){
       cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
 }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}