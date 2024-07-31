#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
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
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
 int n;cin>>n;
 vector<string>arr(2);
 cin>>arr[0]>>arr[1];
 vector<int>pre(n), suff(n);
 
 for(int i=0;i<n;i++){
    pre[i] = (i-1>=0?pre[i-1]:0) + (arr[0][i]=='.') + (arr[1][i]=='.');
 }
 for(int i=n-1;i>=0;i--){
    suff[i] = (i+1<n? suff[i+1] :0) + (arr[0][i]=='.') + (arr[1][i]=='.');
 }int ans = 0;
  
 for(int i=1;i<n-1;i++){
    if(arr[0][i]=='.'){
      ans+=((arr[1][i+1]=='x' ) && (arr[1][i-1]=='x' )  && pre[i-1]>0 && suff[i+1]>0 && arr[1][i]=='.' );
       
    }
    if(arr[1][i]=='.'){
         ans+=((arr[0][i+1]=='x' ) && (arr[0][i-1]=='x') && pre[i-1]>0 && suff[i+1]>0 && arr[0][i]=='.');
    }
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