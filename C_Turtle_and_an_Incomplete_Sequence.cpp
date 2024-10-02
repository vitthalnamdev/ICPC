// Don't look the rank , if you want a good rank
#include <bits/stdc++.h>
using namespace std;
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
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
vector<int> cal(int a, int b)
{
  map<int, bool> check;
  int tempa = a;int tempb = b;
  while (a >= 1)
  {
    check[a] = 1;
    a /= 2;
  }
  int lca;
  while (b >= 1)
  {
    if (check[b])
    {
      lca = b;
      break;
    }
    b /= 2;
  }
  a = tempa;b = tempb;
  vector<int> patha;
  while (a > lca)
  {
    patha.push_back(a);
    a /= 2;
  } 
  patha.push_back(lca);
  vector<int> pathb;
  while (b > lca)
  {
    pathb.push_back(b);
    b /= 2;
  }
  reverse(pathb.begin(), pathb.end());
  for (int i = 0; i < pathb.size(); i++)
  {
    patha.push_back(pathb[i]);
  }
  return patha;
}
void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<int> ind;
  vector<int> ans(n);

  for (int i = 0; i < n; i++)
  {
    if (arr[i] != -1)
    {
      ind.push_back(i);
      ans[i] = arr[i];
    }
  }

   

  if (ind.size() == 0)
  {
    int prev = 1;
    for (int i = 0; i < n; i++)
    {
      cout << prev << " ";
      if (i % 2 == 0)
      {
        prev *= 2;
      }
      else
      {
        prev /= 2;
      }
    }
    cout << endl;
    return;
  }
  
  int x = ind.size();
  for (int i = 0; i < x; i++)
  {
    if (i + 1 < x)
    {
      int sz = ind[i + 1] - ind[i] - 1;
      if (sz == 0)
      {
        continue;
      }
       
      auto temp = cal(arr[ind[i]], arr[ind[i+1]]);
      int sz2 = temp.size() - 2;
      
      if (sz2 > sz || (sz - sz2) % 2)
      {
        cout << -1 << endl;
        return;
      }
      int p1 = 1;
      temp.pop_back();
      int j;
      for (j = ind[i]+1; j < ind[i + 1]; j++)
      {
        
        if (p1 >= temp.size())
        {
          break;
        }
        ans[j] = temp[p1++];
      }
       
      int prev = ans[j - 1];
      int cnt = 0;
       
      for(;j < ind[i + 1]; j++)
      {  
        if (cnt)
        {
          prev/= 2;
        }
        else
        {
          prev*= 2;
        }
        ans[j] = prev;
        cnt ^= 1;
      }
      
    }
  }
  int prev = arr[ind[0]];
  int cnt = 0;
  for (int i = ind[0]-1; i >= 0; i--)
  {
    if (cnt)
    {
      prev /= 2;
    }
    else
    {
      prev*= 2;
    }
    ans[i] = prev;
    cnt ^= 1;
  }

  prev = arr[ind.back()];
  cnt = 0;
  for (int i = ind.back() + 1; i < n; i++)
  {
    if (cnt)
    {
      prev /= 2;
    }
    else
    {
      prev*= 2;
    }
    ans[i] = prev;
    cnt ^= 1;
  }
     
  for(int i=0;i<n-1;i++){
    bool check = 0;
      if((ans[i+1]/2)==ans[i]){check=1;}
      if((ans[i]/2)==ans[i+1])check=1;
    if(check==0){
       cout<<-1<<endl;return;
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
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