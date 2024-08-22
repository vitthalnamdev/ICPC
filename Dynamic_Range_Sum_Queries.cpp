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
struct FenwickTree
{
  vector<ll> bit; // binary indexed tree
  int n;

  FenwickTree(int n)
  {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<ll> const &a) : FenwickTree(a.size())
  {
    for (int i = 0; i < n; i++)
    {
      bit[i] += a[i];
      int r = i | (i + 1);
      if (r < n)
        bit[r] += bit[i];
    }
  }

  ll sum(int r)
  {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }
  ll sum(int l, int r)
  {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta)
  {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};


void yeh_bhi_krr_lete_hain(){
  int n , q;cin>>n>>q;
  vector<ll>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  FenwickTree tree = FenwickTree(arr);
  while(q--)
  {
     int query ;cin>>query;
     if(query==1){
        ll ind , x;cin>>ind>>x;
        tree.add(ind-1 , -arr[ind-1]);
        tree.add(ind-1 , x);
        arr[ind-1] = x;
     }else{
        int a , b;cin>>a>>b;
        cout<<tree.sum(a-1 , b-1)<<endl;
     }
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
yeh_bhi_krr_lete_hain();
}
}