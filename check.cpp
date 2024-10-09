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
class segment{
  vector<ll>tree;
  int n ;
  public:
  segment(ll n){
     this->n = n;
     tree.assign(4*n+4 , 0);
  }
  ll build(vector<ll>&arr , int l , int r , int ind)
  {
     if(l==r){return tree[ind] = arr[l];}
     ll mid = (l+r)/2;
     ll left = build(arr , l , mid , 2*ind+1);
     ll right = build(arr , mid+1 , r , 2*ind+2);
     return tree[ind] = (left + right);
  }
  ll query(int l , int r , int a , int b , int ind)
  { 
    if(l>b || r<a){return 0;} 
    if(l>=a && r<=b){return tree[ind];}
    ll mid = (l+r)/2;
    ll left = query(l , mid , a , b , 2*ind+1);
    ll right = query(mid +1 , r , a , b , 2*ind+2);
    return (left + right);
  }
  ll update(int l ,int r , int i , int ind , int val)
  {
      if(l>i || r<i){return tree[ind];}
      if(l==r && l==i){
         return tree[ind] += val;
      }
      ll mid = (l+r)/2;
      ll left = update(l , mid , i , 2*ind+1 , val);
      ll right = update(mid+1 ,r , i , 2*ind+2 , val);
      return tree[ind] = (left + right);
  }
};

void solve(){
 int n ,q;cin>>n>>q;
 vector<ll>arr(n+1 , 0);
 segment t(n+1);
 t.build(arr , 0 , n-1 , 0);
 while(q--)
 {
    int x;cin>>x;
    if(x==2){
        int ind;cin>>ind;
         
        cout<<t.query(0,n-1,0,ind,0)<<endl;
    }else{
        ll a , b , u;cin>>a>>b>>u; 
        t.update(0,n-1,a,0,u);
        t.update(0,n-1,b,0,-u);
    }
 }
}

  ll inf = INT_MAX;
    void reroot(int v, int p, ll d_up , vector<ll>&d , vector<ll>&d_all , vector<int>adj[]) {
        d_all[v] = max(d[v], d_up);
        vector<int> sons;
        int max1 = -inf, max2 = -inf;
        for (int to: adj[v]) {
            if (to == p) {
                continue;
            }
            sons.push_back(to);
            if (max1 < d[to]) {
                max2 = max1;
                max1 = d[to];
            } else if (max2 < d[to]) {
                max2 = d[to];
            }
        }
        for (int to: sons) {
            reroot(to, v, max(d_up + 1,(ll)(d[to] == max1 ? max2 : max1) + 2) , d , d_all , adj);
        }
    }


class Table
{
public:
    void build(vector<ll> &arr, int n, vector<vector<ll>> &table)
    {
        for (int i = 0; i < n; i++)
        {
            table[i][0] = arr[i];
        }
        for (int j = 1; j < 20; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int now = (i + (1 << (j - 1)));
                if (now >= n)
                {
                    break;
                }
                table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r, vector<vector<ll>> &table)
    {
        int sz = (r - l + 1);
        int cnt = 0;
        for (int i = 0; i < 20; i++)
        {
            int now = (1 << i);
            if (now > sz)
            {
                cnt = i - 1;
                break;
            }
        }
        return max(table[l][cnt], table[r - (1 << cnt) + 1][cnt]);
    }
};


int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}