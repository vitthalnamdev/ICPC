// Don't look the rank , if you want a good rank
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
////--------- DEBUG START---------////
#define debug(x)       \
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
int check(char a, char b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    return -1;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n + 4, vector<int>(n + 4, 0));
     
    for (int i = n; i >= 1; i --)
    {
        for (int j = i ; j <= n; j ++)
        {
            int len = j-i+1;
            if(len%2){continue;}
            int mx1 = -1, mx2 = -1;
            if(dp[i+1][j-1]!=0){
              mx1 = max(mx1 , dp[i+1][j-1]);
            }else{
              mx1 = max(mx1 , check(s[i-1] , s[j-1]));
            }
            if(dp[i+2][j]!=0){
               mx1 = max(mx1 , dp[i+2][j]);
            }else{
               mx1 = max(mx1 , check(s[i-1],s[i]));
            }
            if(dp[i+1][j-1]!=0){
                mx2 = max(mx2 , dp[i+1][j-1]);
            }else{
                mx2 = max(mx2 , check(s[j-1] , s[i-1]));
            }
            if(dp[i][j-2]==0){
                mx2 = max(mx2 , check(s[j-1] , s[j-2]));
            }else{
                mx2 = max(mx2 , dp[i][j-2]);
            }
            dp[i][j] = min(mx1 , mx2);
        }
    }
    
    if (dp[1][n] == -1)
    {
        cout << "Alice" << endl;
    }
    else if (dp[1][n] == 0)
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << "Bob" << endl;
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