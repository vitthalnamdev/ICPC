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
int diff = 0;
string operator |(string &a , string &b)
{
    string ans = "";
    int sz = a.length() - b.length();
    int temp = 0;
    for(int i=0;i<a.length();i++){
        sz--;
        if(sz<0){
          if(b[temp++]=='1' || a[i]=='1'){
            ans+='1';
          }else{
             ans+='0';
          }
        }else{
           ans+=a[i];
        }
    }
    return ans;
}
void yeh_bhi_krr_lete_hain(){
 int n;cin>>n;string s;cin>>s;
 int cnt =0;
 int i = 0;
 for(i = 0;i<n;i++){
    if(s[i]=='1'){
        break;
    }
 }
 if(i==n){
    cout<<0<<endl;return;
 }
  s = s.substr(i , n);
   
  n = s.length();
  int fzero = 0;
  for(int i=0;i<n;i++)
  {
     if(s[i]=='0'){
        fzero = i;break;
     }
  }
  diff = n-fzero;
  string ans = "";
  for(int i=0;i<diff;i++)ans+='0';
  for(int i=0;i<fzero;i++){
     string now = "";
     for(int j = i;j<i+diff;j++){
        now+=s[j];
     }
     debug(now)
    string temp = s | now;
    ans = max(ans ,temp );
  }
  cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t = 1;
while(t--){
yeh_bhi_krr_lete_hain();
}
}