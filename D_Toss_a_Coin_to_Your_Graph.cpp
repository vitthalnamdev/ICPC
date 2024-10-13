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

ll dfs(int node, vector<int> adj[], vector<int> &arr, int mx, vector<int> &vis1, vector<int> &vis2, vector<ll> &dp)
{
    if (arr[node] > mx)
    {
        return dp[node] = 0;
    }
    vis1[node] = 1;
    vis2[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis1[i])
        {
            ll curr = dfs(i, adj, arr, mx, vis1, vis2, dp);
            if (curr == LLONG_MAX)
            {
                return dp[node] = curr;
            }
            else
            {
                dp[node] = max(dp[node], curr + 1);
            }
        }
        else if (vis2[i])
        {
            return dp[node] = LLONG_MAX;
        }
        else
        {
            dp[node] = max(dp[node], dp[i] + 1);
        }
    }
    vis2[node] = 0;
    return dp[node];
}

bool check(int mx, vector<int> adj[], vector<int> &arr, ll k, ll n)
{
    vector<int> vis1(n + 1, 0);
    vector<int> vis2(n + 1, 0);
    vector<ll> dp(n + 1, 1);
    for (int i = 0; i < n; i++)
    {
        if (!vis1[i])
        {
            ll ans = dfs(i, adj, arr, mx, vis1, vis2, dp);
            if (ans >= k)
            {

                return true;
            }
        }
    }

    return false;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }

    int start = 1, end = 1e9;
    while (end - start > 1)
    {
        int mid = (start + end) / 2;
        if (check(mid, adj, arr, k, n))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (check(start, adj, arr, k, n))
    {
        cout << start << endl;
    }
    else if (check(end, adj, arr, k, n))
    {
        cout << end << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}