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

class segment
{
public:
    int n;
    vector<vector<ll>> tree;
    segment(ll n)
    {
        this->n = n;
        tree.assign(4 * n + 4, vector<ll>(4, INT_MAX));
    }
    vector<ll> build(vector<ll> &arr, int l, int r, int ind)
    {
        if (l == r)
        {
            tree[ind][0] = max(0LL, arr[l]);
            tree[ind][1] = tree[ind][0];
            tree[ind][2] = tree[ind][0];
            tree[ind][3] = arr[l];
            return tree[ind];
        }
        int mid = (l + r) / 2;
        auto left = build(arr, l, mid, 2 * ind + 1);
        auto right = build(arr, mid + 1, r, 2 * ind + 2);
        tree[ind][0] = max(left[0], max(right[0], left[2] + right[1]));
        tree[ind][1] = max(left[1], left[3] + right[1]);
        tree[ind][2] = max(right[2], right[3] + left[2]);
        tree[ind][3] = left[3] + right[3];
        return tree[ind];
    }
    
    vector<ll> update(int l, int r, int i, int ind, ll val)
    {
        if (l > i || r < i)
        {
            return tree[ind];
        }
        if (l == r && l == i)
        {
            tree[ind][0] = max(0LL, val);
            tree[ind][1] = tree[ind][0];
            tree[ind][2] = tree[ind][0];
            tree[ind][3] = val;
            return tree[ind];
        }
       int mid = (l + r) / 2;
        auto left =  update(l , mid , i , 2*ind+1 , val);
        auto right = update(mid+1 , r , i , 2*ind + 2 , val);
        tree[ind][0] = max(left[0], max(right[0], left[2] + right[1]));
        tree[ind][1] = max(left[1], left[3] + right[1]);
        tree[ind][2] = max(right[2], right[3] + left[2]);
        tree[ind][3] = left[3] + right[3];
        return tree[ind];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    segment t(n+1);
    t.build(arr , 0 , n-1 , 0);
    cout<<t.tree[0][0]<<endl;
    while (m--)
    {
        int ind, ele;
        cin >> ind >> ele;
        arr[ind] = ele;
        t.update(0 , n-1 , ind , 0 , ele);
        cout<<t.tree[0][0]<<endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t=1;
    while (t--)
    {
        solve();
    }
}