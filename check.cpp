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
int  countPalindromicSubsequences(string s) {
        int n = s.length();
        int mod = 1e9+7;
        vector<vector<long long int >>dp(n , vector<long long int>( n , 0));
        for(int i=0;i<n;i++){
          dp[i][i] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(s[j]==s[i] ){
                  dp[j][i] =  1;
                  dp[j][i]%=mod;
                }
                dp[j][i] += dp[j][i-1] + dp[j+1][i] - (j+1>i-1?0:dp[j+1][i-1]);
                dp[j][i]%=mod;
            }
        }
   debug(dp)
    return dp[0][n-1]%mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
 string a = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
 cout<<countPalindromicSubsequences(a)<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
 
int t;cin>>t;
while(t--){
solve();
}
}