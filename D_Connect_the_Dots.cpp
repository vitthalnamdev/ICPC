// Don't look the rank , if you want a good rank
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
class Dsu
{
public:
  Dsu(int x)
  {
    rank = new int[x + 1];
    parent = new int[x + 1];
    for (int i = 0; i <= x; i++)
      rank[i] = 0;
    for (int i = 0; i <= x; i++)
      parent[i] = i;
  }
  int *rank;
  int *parent;

  int find(int a)
  {
    if (parent[a] == a)
      return a;
    return find(parent[a]);
  }
  bool same(int a, int b)
  {
    return find(a) == find(b);
  }

  bool Draw_edge(int a, int b)
  {
    int parenta = find(a);
    int parentb = find(b);

    if (parenta == parentb)
    {
      return false;
    }

    if (rank[parenta] > rank[parentb])
    {
      parent[parentb] = parenta;
    }
    else if (rank[parentb] > rank[parenta])
    {
      parent[parenta] = parentb;
    }
    else
    {
      parent[parentb] = parenta;
      rank[parenta]++;
    }

    return true;
  }
};

void solve()
{
  int n;
  cin >> n;
  int m;
  cin >> m;

  Dsu tree(n + 1);

  vector<vector<int>> arr(m);

  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    arr[i] = {x, y, z};
  }

  sort(arr.begin(), arr.end() , [](vector<int>&a , vector<int>&b){
     if(a[0]==b[0])
     {
        return a[2]<b[2];
     }
     return a[0]<b[0];
  });
  
  map<int, map<int, int>> ispresent, end;
  int p1 = 0;
  for (int i = 1; i <= n; i++)
  {
    int curr = i;
    for (int j = 1; j <= 10; j++)
    {
      int now = (curr) % j;
      if (ispresent[j][now] > 0 && end[j][now] >= curr)
      {
        tree.Draw_edge(curr, ispresent[j][now]);
      }
    }
    if (p1 < m && curr == arr[p1][0])
    {
      int now = (arr[p1][0] % arr[p1][1]);
      ispresent[arr[p1][1]][now] = arr[p1][0];
      end[arr[p1][1]][now] = max(end[arr[p1][1]][now] , (arr[p1][0] + arr[p1][1] * arr[p1][2]));
      p1++;
      if (p1 < m && arr[p1][0] == i)
      {
        i--;
      }
    }
  }
  set<int> s;
  for (int i = 1; i <= n; i++)
  {
    s.insert(tree.find(i));
  }
  cout << s.size() << endl;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}