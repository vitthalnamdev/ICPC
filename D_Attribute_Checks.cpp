// Don't look the rank , if you want a good rank
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
////--------- DEBUG START---------////
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
void _print(int a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(long long int a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(bool a) { cerr << a; }
template <class T1, class T2>
void _print(pair<T1, T2> a)
{
  cerr << "{ ";
  cerr << a.first << " " << a.second;
  cerr << " }";
}
template <class T>
void _print(vector<T> &a)
{
  cerr << "[ ";
  for (T i : a)
  {
    _print(i);
    cerr << " ";
  }
  cerr << " ]";
}
template <class T>
void _print(set<T> &a)
{
  cerr << "[ ";
  for (T i : a)
  {
    _print(i);
    cerr << " ";
  }
  cerr << " ]";
}
template <class T>
void _print(multiset<T> &a)
{
  cerr << "[ ";
  for (T i : a)
  {
    _print(i);
    cerr << " ";
  }
  cerr << " ]";
}
////------DEBUG END---------////
int mod = 1e9 + 7;
ll inv(ll a)
{
  return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}
long long binpow(long long a, long long b, long long m)
{
  a %= m;
  long long res = 1;
  while (b > 0)
  {
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
// flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
vector<int> arr;
vector<vector<int>> dp(5001, vector<int>(5001));
void solve()
{
  int n;
  cin >> n;
  int m;
  cin >> m;
  arr.resize(n);
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  ordered_multiset<int> intelligence, strength;

  int ans = 0;
  int total = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      total++;strength.clear();intelligence.clear();i++;
      while ((i < n) && (arr[i])!= 0)
      {
        if (arr[i] < 0)
        { 
          strength.insert(abs(arr[i]));
        }
        else
        {
          intelligence.insert(arr[i]);
        }
        i++;
      }
       
      for (int j = 0; j <= total; j++)
      {
        int strengthlower = strength.order_of_key(j + 1);
        int intillegencelower = intelligence.order_of_key(total - j + 1);
        dp[total][j] = max((j-1>=0?dp[total - 1][j-1]:0) + strengthlower + intillegencelower\
         , dp[total-1][j] + strengthlower + intillegencelower);
        ans = max(ans, dp[total][j]);
      }
      
      i--;
    }
  }
  cout << ans << endl;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t = 1;
  while (t--)
  {
    solve();
  }
}