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
int cal(int ind , vector<pair<int,int>>&arr)
{
   int ans = 0;
   ans+=(arr[ind].second<arr[ind-1].second);
   ans+=(arr[ind+1].second<arr[ind].second);
   return ans;
}
void solve(){
 int n , q;cin>>n>>q;
 vector<pair<int,int>>arr(n+2);
 for(int i=1;i<=n;i++){
    cin>>arr[i].first;
    arr[i].second = i;
 }
 arr[0].first = -1;arr[n+1].first = INT_MAX;
 sort(arr.begin()+1 , arr.end());
 
 vector<int>mapping(n+2);
 for(int i=1;i<=n;i++){
    mapping[arr[i].second] = i;
 }
 arr[0].second = -1;arr[n+1].second = INT_MAX;
 int ans = 1;
  
  
 for(int i=2;i<=n;i++){
    if(arr[i].second<arr[i-1].second){ans++;}
 }
 
 while(q--)
 {
    int l , r;cin>>l>>r;
    l = mapping[l];r = mapping[r];
   
     
    if(l>r)swap(l,r);
    ans-=(cal(l , arr));
    ans-=(cal(r , arr));
    if(r==l+1 && arr[l].second>arr[r].second){
       ans++;
    }
    swap(arr[l].second , arr[r].second);
    mapping[arr[l].second] = l;
    mapping[arr[r].second] = r;
    ans+=(cal(l , arr));
    ans+=(cal(r , arr));
    if(r==l+1 && arr[l].second>arr[r].second){
       ans--;
    }
    mapping[arr[l].second] = l;

    cout<<ans<<endl;
 }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}