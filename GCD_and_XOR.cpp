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
    ll k;
    cin >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int check = 1;

    ll prev = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
            check = 0;
        prev = __gcd(prev, arr[i + 1]);
    }
    if (check && arr[0] == k)
    {   
        cout << 0 << endl;
        return;
    }
    if (check && arr[0] != k)
    {
        cout << 1 << endl;
        return;
    }

    int ind = 0;
    int last = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != k)
        {
            ind = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != k)
        {
            last = i;
            break;
        }
    }

    check = true;

    for (int i = ind; i < last; i++)
        if (arr[i] != arr[i + 1])
            check = false;

    if (prev % k == 0 || check)
        cout << 1 << endl;
    else
        cout << 2 << endl;

    return;
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