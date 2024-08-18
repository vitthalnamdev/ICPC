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

void dfs(int node, int parent, vector<ll> &level, vector<int> adj[])
{
    for (auto i : adj[node])
    {
        if (i == parent)
        {
            continue;
        }
        dfs(i, node, level, adj);
        level[node] = max(level[node], level[i] + 1);
    }
}
void dfs2(int node, int parent, vector<ll> &level, vector<int> adj[])
{
     
    for (auto i : adj[node])
    {   

        if (i == parent)
        {
            continue;
        }

        level[i] = level[node] + 1;
        dfs2(i, node, level, adj);
    }
}

ll inf = INT_MIN;
void reroot(int v, int p, ll d_up, vector<ll> &d, vector<ll> &d_all, vector<int> adj[])
{
    d_all[v] = max(d[v], d_up);
    vector<int> sons;
    int max1 = -inf, max2 = -inf;
    for (int to : adj[v])
    {
        if (to == p)
        {
            continue;
        }
        sons.push_back(to);
        if (max1 < d[to])
        {
            max2 = max1;
            max1 = d[to];
        }
        else if (max2 < d[to])
        {
            max2 = d[to];
        }
    }
    for (int to : sons)
    {
        reroot(to, v, max(d_up + 1, (ll)(d[to] == max1 ? max2 : max1) + 2), d, d_all, adj);
    }
}
void yeh_bhi_krr_lete_hain()
{

    ll n, k, c;
    cin >> n >> k >> c;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> level(n + 1, 0);
    dfs(1, -1, level, adj);
    vector<ll> dist(n + 1, 0);
    reroot(1, -1, 0, level, dist, adj);
    ll ans = 0;
    for (int i = 0; i <= n; i++)level[i] = 0;
    dfs2(1, -1, level, adj);
     for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i] * k - level[i] * c);
    }
    cout << ans << endl;
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
        yeh_bhi_krr_lete_hain();
    }
}