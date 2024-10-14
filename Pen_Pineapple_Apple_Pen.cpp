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
 int n;cin>>n;
 int k;cin>>k;
 string s;cin>>s;
 int c = 20;
 int total = (1<<c);
 vector<int>f(total + 1 , 0);
 for(int i=1;i<=k;i++){
    string now;cin>>now;
	int mask = 0;
	for(int j=0;j<now.length();j++){
	   mask|=(1<<(now[j]-'a'));
	}
	f[mask] = i;
 }

 for(int i=0;i<c;i++){
	for(int j=total-1;j>=0;j--){
       if(!(j&(1<<i)) && f[j]==0){
		  f[j] = (f[j|(1<<i)]);
	   }
	}
 }
  int prev = 0;
  for(int i=0;i<n;i++){
	 int mask = (1<<(s[i]-'a'));
  
	 while(i+1<n && f[mask|(1<<(s[i+1]-'a'))]){
		 
		mask|=(1<<(s[i+1]-'a'));
		i++;
	 }
	 for(int j=prev;j<=i;j++){
		cout<<f[mask]<<" "; 
	 }
	 prev = i+1;
  } 
  cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}