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
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> odd(n + 2, vector<int>(26, 0));
    vector<vector<int>> even(n + 2, vector<int>(26, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            odd[i][j] = odd[i - 1][j];
            even[i][j] = even[i - 1][j];
        }
        if (i % 2 == 1)
        {
            odd[i][s[i - 1] - 'a']++;
        }
        else
        {
            even[i][s[i - 1] - 'a']++;
        }
    }
    if (n % 2 == 0)
    {
        int mxeven = 0, mxodd = 0;
        for (int i = 0; i < 26; i++)
        {
            mxeven = max(mxeven, odd[n][i]);
            mxodd = max(mxodd, even[n][i]);
        }
        cout << n - (mxeven + mxodd) << endl;
    }
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            vector<int> oddnow(26, 0);
            vector<int> evennow(26, 0);
         
            for (int j = 0; j < 26; j++)
            {
                oddnow[j] += (odd[i - 1][j] + (even[n][j] - even[i][j]));
                evennow[j] += (even[i - 1][j] + (odd[n][j] - odd[i][j]));
            }

            int mxeven = 0, mxodd = 0;
            for (int j = 0; j < 26; j++)
            {
                mxeven = max(mxeven, oddnow[j]);
                mxodd = max(mxodd, evennow[j]);
            }
            ans = min(ans, n - mxeven - mxodd);
        }
        cout << ans << endl;
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