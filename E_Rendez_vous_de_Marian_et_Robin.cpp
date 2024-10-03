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
void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i.first])
        {
            dfs(i.first, adj, vis);
        }
    }
}

void shortest(int node, vector<vector<ll>> &dist, vector<pair<int, int>> adj[], vector<int> &arr)
{
    int n = dist.size();
    set<pair<ll, pair<int, int>>> s;
    vector<int> ispresent(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        ispresent[arr[i]] = 1;
    }
    s.insert({0, {node, ispresent[node]}});
    dist[node][0] = 0;
    dist[node][ispresent[node]]=0;
    set<pair<int,int>>vis;
    while (!s.empty())
    {
        auto top = *s.begin();
        s.erase(s.begin());

        bool present = (top.second.second | ispresent[top.second.first]);
        auto check = vis.find(top.second);
        if(check!=vis.end())
        {
            continue;
        }
        vis.insert(top.second);
        for (auto i : adj[top.second.first])
        {
            ll w = i.second;
            if (present)
                w /= 2;
            if (dist[i.first][present] > dist[top.second.first][top.second.second] + w)
            {     
                dist[i.first][present] = dist[top.second.first][top.second.second] + w;
                s.insert({dist[i.first][present], {i.first, present}});   
            }
        }
    }
}

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<pair<int, int>> adj[n + 1];
    vector<int> arr;

    for (int i = 0; i < h; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> vis(n + 1, 0);
    dfs(1, adj, vis);
    if (vis[n] == 0)
    {
        cout << -1 << endl;
        return;
    }

    vector<vector<ll>> dist1(n+1, vector<ll>(2, LLONG_MAX));
    shortest(1, dist1, adj, arr);

    vector<vector<ll>> dist2(n+1, vector<ll>(2, LLONG_MAX));
    shortest(n, dist2, adj, arr);
    ll ans = LLONG_MAX;
    
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, max(min(dist1[i][1], dist1[i][0]), min(dist2[i][1], dist2[i][0])));
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
        solve();
    }
}