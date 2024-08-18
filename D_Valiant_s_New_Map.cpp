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
bool check(int mid , vector<vector<int>>&arr)
{
    int n = arr.size();int m = arr[0].size();
    vector<vector<int>>prefix(n+1 ,vector<int>(m+1 , 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prefix[i+1][j+1] = prefix[i+1][j] + prefix[i][j+1] - prefix[i][j] + (arr[i][j]>=mid);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int startrow = i+1;
            int startcol = j+1;
            int endrow = i + mid;
            int endcol = j + mid;
            if(endrow>n || endcol>m){break;}
            int total = prefix[endrow][endcol] - prefix[startrow-1][endcol] - prefix[endrow][startcol-1] + prefix[startrow-1][startcol-1];
            if(total==mid*mid)
            {
                return true;
            }
        }
    }
    return false;
}
void yeh_bhi_krr_lete_hain(){
 int n , m;cin>>n>>m;
 vector<vector<int>>arr(n , vector<int>(m));
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<m;j++)
    {
        cin>>arr[i][j];
    }
 }
  int start = 1 , end = min(n ,m);
  while(end - start > 1)
  {
     int mid = (start + end )/2;
     if(check(mid , arr))
     {
        start = mid;
     }else{
        end = mid - 1;
     }
  }
  if(check(end , arr))
  {
    cout<<end<<endl;
  }else{
    cout<<start<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
yeh_bhi_krr_lete_hain();
}
}