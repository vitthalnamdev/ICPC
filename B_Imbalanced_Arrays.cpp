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
void solve(){
  int n;cin>>n;
  vector<pair<int,int>>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i].first , arr[i].second = i;
  sort(arr.begin(),arr.end());
  int p1 = 0;int p2 = n-1;
  int val = n;
  vector<int>ans(n);
  while(p2>=p1){
     if((n-p1==arr[p2].first)^(n-p2-1==arr[p1].first))
     { 
      
        if(arr[p2].first==n-p1){
          ans[arr[p2--].second] = val--;
        }else{
          ans[arr[p1++].second] = -(val--);
        }
     }else{
        cout<<"NO"<<endl;
        return;
     }
  }
  cout<<"YES"<<endl;
  for(auto i:ans){
    cout<<i<<" ";
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
