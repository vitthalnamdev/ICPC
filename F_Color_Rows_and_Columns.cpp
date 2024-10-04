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
int cal(int cnt, int a, int b)
{
    if (cnt == (a + b))
    {
        return a * b;
    }
    if(cnt==0){
        return 0;
    }
    if (cnt > (a + b))
    {
        return INT_MAX;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= min(cnt, b); i++)
    {
        ans = min(ans, a * i + max(0, (b - i) * (cnt - i)));
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        sort(arr[i].begin(), arr[i].end());
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= k; j++)
        {
            for (int l = 0; l <= j; l++)
            {
                int tot = (arr[i][0] + arr[i][1]);
                int curr = cal(l , arr[i][0] , arr[i][1]);
                if(dp[i][j-l]!=INT_MAX && curr!=INT_MAX)
                dp[i + 1][j] = min(dp[i+1][j] , dp[i][j-l] + curr); 
            }
        }
    }
     
    if (dp[n][k] == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << dp[n][k] << endl;
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