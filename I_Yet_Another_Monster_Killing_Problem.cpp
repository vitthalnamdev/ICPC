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
const int N = 200010;
int t;
int n;
 
int m;
int p[N], s[N];
int best[N];
ll arr[N];
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
 

void solve(){  
        cin>>n;
        int best[n+10];
		for(int i = 0; i <= n; ++i) best[i] = 0;
		for(int i = 0; i < n; ++i)
			cin>>arr[i];
		int m;cin>>m;
       
		for(int i = 0; i < m; ++i){
			cin>>p[i]>>s[i];
			best[s[i]] = max(best[s[i]], p[i]);
		}
		for(int i = n - 1; i >= 0; --i)
			best[i] = max(best[i], best[i + 1]);	
		

		int pos = 0;
		int res = 0;
		bool ok = true;
		while(pos < n){
			++res;
			ll npos = pos;
			ll mx = 0;
			while(true){
				mx = max(mx, arr[npos]);
				if(npos-pos+1>=0 && mx > best[npos - pos + 1]) break;
				++npos;
			}
	
			if(pos == npos){
				ok = false;
				break;
			}
			pos = npos;
		}

		if(!ok) res = -1;
		cout<<res<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}