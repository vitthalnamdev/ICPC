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
void yeh_bhi_krr_lete_hain(){
 int n ;cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)cin>>arr[i];
 int count[101];
 for(int i=0;i<=100;i++){
    count[i] = 0;
 }
 for(int i=0;i<n;i++){
    count[arr[i]]++;
 }
//  int ans1 = -1;
//  for(int i=2;i<=100;i++){
//     if(count[i]>1){
//         ans1 = i;break;
//     }
//  }
 
//  int cnt = 0;
//  for(int i=0;i<n;i++){
//      if(arr[i]==ans1){
//         cout<<i+1<<" ";cnt++;
//      }
//      if(cnt==2){
//         break;
//      }
//  }
//  if(cnt==2){
//     cout<<endl;return;
//  }
 pair<int,int>ans = {-1 , -1};
 for(int i=1;i<=100;i++){
    if(count[i]==0){
        continue;
    }
    if(i!=1 && count[i]>1){
        ans.first = i;ans.second = i;break;
    }
    for(int j=i+1;j<=100;j++){
        // if(i==j)continue;
        if(count[j]>0){
           int cnt = 0;
           int num = i+j;
           for(int k=2;k<=sqrt(num);k++)
           {
            if(num%k==0){
                ans.first=i , ans.second = j;break;
            }
           }
        }
    }
    if(ans!=make_pair(-1,-1)){
        break;
    }
 }
pair<int,int>result={-1, -1};
 for(int i=0;i<n;i++){
    if(arr[i]==ans.first && result.first==-1){
        result.first = i+1;
        continue;
    }
    if(arr[i]==ans.second && result.second==-1)
    {
        result.second = i+1;
        continue;
    }

 }
 if(ans==make_pair(-1 , -1)){
    cout<<-1<<endl;
}else{
 cout<<result.first<<" "<<result.second<<endl;
}
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
yeh_bhi_krr_lete_hain();
}
}