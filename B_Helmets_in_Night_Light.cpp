#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")

#ifdef LOCAL_PROJECT
#define debug(x) cerr << #x <<" "; _print(x); cerr<< endl;
#else
#define debug(x)
#endif

void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(long long int a ){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr << a;}
template<class T1, class T2> void _print(pair<T1,T2> a){cerr<<"{ ";cerr<<a.first<<" "<<a.second;cerr<<" }";}
template<class T> void _print(vector<T>& a){cerr<<"[ "; for(T i:a){_print(i);cerr<<" ";} cerr<<" ]";}
template<class T> void _print(set<T>& a){cerr<<"[ "; for(T i:a){_print(i);cerr<<" ";} cerr<<" ]";}
template<class T> void _print(multiset<T>& a){cerr<<"[ "; for(T i:a){_print(i);cerr<<" ";} cerr<<" ]";}

int mod = 1e9+7;

ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
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

void solve() {
  ll n ,  p;cin>>n>>p;

  vector<vector<ll>>arr(n , vector<ll>(2));
  for(int i=0;i<n;i++){
     cin>>arr[i][0];
  }
  for(int i=0;i<n;i++){
     cin>>arr[i][1];
  }
  sort(arr.begin() , arr.end() , [](vector<ll>a , vector<ll>b){
    return a[1]<b[1];
  });
   
  ll ans = p;
  ll left = n-1;
  for(int i=0;i<n;i++){
     ans+=(min(left , arr[i][0])*min(p,arr[i][1]));
     left-=(arr[i][0]);
     if(left<=0){
       break;
     }
  }
  cout<<ans<<endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
