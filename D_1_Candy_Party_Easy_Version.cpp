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
int find(int n )
{
    for(int i=31;i>=0;i--)
    {
        int now  = (n&(1<<i));
        if(now>0){
            return now;
        }
    }
    return 0;
}

bool ans(vector<int>&arr)
{
    int n = arr.size();
    ll sum = 0;
    for(int i=0;i<n;i++){sum+=arr[i];}
    if(sum%n){
         
        return 0;
    }
   
    sum/=n;
    vector<int>bit(37 , 0);
    for(int i=0;i<n;i++){
        if(arr[i]==sum){
            continue;
        }
        ll val = abs(sum - arr[i]);
        ll now = (val&(-val));
        
        ll curr = val + now;
         
        if(__builtin_popcount(curr)==1)
        {
            if(arr[i]>sum){
                bit[__lg(curr)]++;
                bit[__lg(now)]--;
            }else{
                bit[__lg(curr)]--;
                bit[__lg(now)]++;
            }
        }else{
            return 0;
        }
    }
    for(int i=0;i<=36;i++){
        if(bit[i]){
            return 0;
        }
    }
    return 1;
}
void solve(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   bool check = ans(arr);
   cout<<(check?"Yes":"No")<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}