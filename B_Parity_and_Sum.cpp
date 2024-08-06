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
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void yeh_bhi_krr_lete_hain(){
 int n;cin>>n;
vector<ll>arr(n);
 for(int i=0;i<n;i++)cin>>arr[i];
 sort(arr.begin() , arr.end());
 ll last = -1;
  
 ll cnt = 0;
 ll cnt2 = 0;
 ll mx = 0;
 vector<ll>even;
 for(int  i=n-1;i>=0;i--){
    if(arr[i]&1 && last==-1){
         last = i;mx = arr[last];
    }
    if((arr[i]&1)==0 && last!=-1){
        cnt++; even.push_back(arr[i]);
    }
    if((arr[i]&1)==0 && last==-1){
        cnt2++;
         even.push_back(arr[i]);
    }
 }
 if(last==-1 || mx==0){
    cout<<0<<endl;return;
 }
 ll ans = 0;
  sort(even.begin() , even.end());
   for(int i=0;i<even.size();i++){
     if(mx <= even[i]){
        ans++;break;
     }
     mx+=even[i];
   }
 ans += (cnt + cnt2);
 cout<<ans<<endl;
  
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
yeh_bhi_krr_lete_hain();
}
}