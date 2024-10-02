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

class Euler_Lca
{
    public:
    int ind = 0;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &depth, vector<int> &nodes, int height)
    {

        for (auto i : adj[node])
        {
            if (i == parent)
            {
                continue;
            }
            depth[ind] = height;
            nodes[ind++] = node;
            dfs(i, node, adj, depth, nodes, height + 1);
        }
        depth[ind] = height;
        nodes[ind++] = node;
    }
    class Table
    {
    public:
        pair<int, int> mini(pair<int, int> &a, pair<int, int> &b)
        {
            if (a.first < b.first)
                return a;
            return b;
        }

        void build(vector<int> &arr, int n, vector<vector<pair<int, int>>> &table)
        {
            for (int i = 0; i < n; i++)
            {
                table[i][0] = {arr[i], i};
            }
            for (int j = 1; j < 20; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    int now = (i + (1 << (j - 1)));
                    if (now >= n)
                    {
                        break;
                    }
                    table[i][j] = mini(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
        int query(int l, int r, vector<vector<pair<int, int>>> &table)
        {
            int sz = (r - l + 1);
            int cnt = 0;
            for (int i = 0; i < 20; i++)
            {
                int now = (1 << i);
                if (now > sz)
                {
                    cnt = i - 1;
                    break;
                }
            }
            auto temp = mini(table[l][cnt], table[r - (1 << cnt) + 1][cnt]);
            return temp.second;
        }
    };
};

void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(2 * n - 1, 0);
    vector<int> nodes(2 * n - 1, 0);
    Euler_Lca obj;
    obj.dfs(0, -1, adj, depth, nodes, 0);
    vector<int> last(n, -1);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        last[nodes[i]] = i;
    }
    Euler_Lca::Table ref;
    vector<vector<pair<int, int>>> table(2 * n - 1, vector<pair<int, int>>(20, {INT_MAX, 0}));
    ref.build(depth, 2 * n - 1, table);
    int a, b;
    cin >> a >> b;
    int ans = ref.query(min(last[a], last[b]), max(last[a], last[b]), table);

    cout << nodes[ans] << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
}