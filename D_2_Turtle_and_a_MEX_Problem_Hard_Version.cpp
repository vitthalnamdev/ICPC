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
ll n , m;cin>>n>>m;
vector<set<int>>arr;
map<ll,ll>mx;
ll val = 0;
int sz = 0;
int t =0;
vector<pair<ll,ll>>value;
for(int i=0;i<n;i++)
{
    int x;cin>>x;
    set<ll>s;
    for(int j=0;j<=x+1;j++){
       s.insert(j);
    }
    for(int j=0;j<x;j++)
    {
       int y;cin>>y;
       auto ele = s.find(y);
       if(ele!=s.end())
       s.erase(ele);
    }
    
    ll mex = *s.begin();
    t = max((ll)t , mex);
    s.erase(s.begin());
    ll now = *s.begin();
    val = max(val , now);
    value.push_back({mex , now});
}
vector<int>dp(val+1 , 0);
vector<int>adj[val+1];
for(auto i:value)
{
     adj[i.first].push_back(i.second);
}

for (int u = val; u>=0; --u) {
		dp[u] = u;
		for (int v : adj[u]) {
			dp[u] = max(dp[u], dp[v]);
		}
		if ((int)adj[u].size() >= 2) {
			t = max(t, dp[u]);
		}
	}

ll ans = 0;
ans+=(m*(m+1))/2;
ans-=(val*(val+1))/2;
ans = max(ans , 0LL);
 val = min(val , m);
 for(int i=0;i<=val;i++){
    ans+=max(t , dp[i]);
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