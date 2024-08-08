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
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
vector<int> vis(200010, 0);
vector<ll> sum(200010, 0);
ll ans = 0;
void dfs(int node, int parent, vector<int> adj[], vector<ll> &dist, vector<ll> &arr)
{
    vis[node] = 1;
    sum[node] += arr[node];
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, node, adj, dist, arr);
            sum[node] += sum[i];
            dist[node] += ((dist[i]) + sum[i]);
        }
    }
}

void rerooting(int node, int parent, vector<ll> &dp, vector<ll> &dist, vector<int> adj[], vector<ll> &arr)
{
    ans = max(ans, dp[node]);
    for (auto i : adj[node])
    {
        if (i == parent)
        {
            continue;
        }
       
        dp[node] -= (sum[i] + dist[i]);  
        sum[node] -= (sum[i]);
        dp[i] = dist[i] + dp[node]  + sum[node];
        sum[i] = sum[node] + sum[i];
        rerooting(i, node, dp, dist, adj, arr);
        sum[i] -= sum[node];
        sum[node]+=sum[i];
        dp[node] += (sum[i] + dist[i]);
    }
}

void yeh_bhi_krr_lete_hain()
{
    int n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<int> adj[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> dist(n + 1, 0);
    vector<ll> dp(n + 1, 0);
    dfs(1, 0, adj, dist, arr);
    
    dp[1] = dist[1];
     
    rerooting(1, 0, dp, dist, adj, arr);
    
    cout << ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    while (t--)
    {
        yeh_bhi_krr_lete_hain();
    }
}