// Don't look up the rank , if you want a good rank.
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

int remove(const string &s , const string &rm){
     int m = rm.size();
     int factor = rm.size() - 1;
     vector<int>dp(m+1 , 0);
     dp[0] = INT_MAX;
     for(auto i: s){
        for(int j=1;j<=m;j++){
           if(i!=rm[j-1]){
             continue;
           }
           if(dp[j-1]>0){
             dp[j-1]--;
             dp[j]++;
           }
        }
     }
     
     if(dp[m]==0){
      return 0;
     }
     int ans = dp[m] + dp[m-1] ;
     int left = dp[m] - 1;
     int cnt = 1;
     for(int i=m-2;i>=1;i--)
     {
        if(left<=cnt){break;}
        int req = dp[i];
        int now = (left-1)/cnt;
        int used = min(req , now);
        left-=(used*cnt + 1);
        ans+=(min(used , now));
        cnt++;
     }
     return ans*factor;
}


// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
void yeh_bhi_krr_lete_hain(){
 int N ;cin>>N;
 string s;cin>>s;
 ll ans = 0;
 ans += (remove(s , "front"));
 reverse(s.begin() , s.end());
 ans += (remove(s , "kcab"));
 cout<<N-ans<<'\n';
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
yeh_bhi_krr_lete_hain();
}
}
