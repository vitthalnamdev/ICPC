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
// flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

void solve()
{
  vector<string> arr;
  int N;
  cin >> N;
  arr.resize(N);
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  map<char, int> val;
  val['w'] = 0;
  val['i'] = 1;
  val['n'] = 2;
  map<int,char>inval;
  inval[0]='w';inval[1]='i';inval[2]='n';
  vector<vector<int>>trade[3];
  for(int i=0;i<3;i++){
     trade[i].resize(3);
  }  
  for(int i=0;i<N;i++){
    int cnt[3]={0,0,0};
    for(int j = 0; j<3; j++){
       cnt[val[arr[i][j]]]++;
    }
    for(int j=0;j<3;j++){
      while(cnt[j]>1){
         cnt[j]--;
         for(int k=0;k<3;k++){
            if(cnt[k]==0){
               trade[j][k].push_back(i+1);
               cnt[k]++;break;
            }
         }
      }
    }
  }
  vector<vector<char>>ans;vector<vector<int>>ind;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(i==j){continue;}
       while(trade[i][j].size()>0 && trade[j][i].size()>0){
           ind.push_back({trade[i][j].back() , trade[j][i].back()});
           ans.push_back({inval[i] , inval[j]});
           trade[i][j].pop_back();trade[j][i].pop_back();
       }
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
       for(int k=0;k<3;k++){
          while(trade[i][j].size()>0 && trade[k][i].size()>0){
            ind.push_back({trade[i][j].back() , trade[k][i].back()});
            ans.push_back({inval[i] , inval[k]});
            if(trade[j][k].size()>0){
               ind.push_back({trade[i][j].back() , trade[j][k].back()});
               ans.push_back({inval[k] , inval[j]});
               trade[j][k].pop_back();
            } 
            trade[i][j].pop_back();trade[k][i].pop_back();
          }
       }
    }
  }
   
  cout<<ind.size()<<endl;
  for(int i=0;i<ind.size();i++){
    cout<<ind[i][0]<<" "<<ans[i][0]<<" "<<ind[i][1]<<" "<<ans[i][1]<<endl;
  }
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