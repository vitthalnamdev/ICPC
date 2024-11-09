// Don't look the rank , if you want a good rank
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
// flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
ll get(ll n)
{
    if(n<=0){
        return 0;
    }
    if (n % 4 == 0)
    {
        return n;
    }
    else if (n % 4 == 1)
    {
        return 1;
    }
    else if (n % 4 == 2)
    {
        return n+1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    ll l, r, i, k;
    cin >> l >> r >> i >> k;
    ll ans = (get(r) ^ get(l - 1));
    
    auto cal = [&](ll number)->long long int
    {
        ll num = (number % (1 << i));
        ll checkfinal = 0;
        for (int j = 63; j >= i; j--)
        {
            if ((number & (1LL << j))){
                checkfinal |= (1LL << j);
            }
        }
        checkfinal >>= (i); 
        
        return max(0LL , checkfinal);
    };
    ll forr = cal(r);
    ll forl = cal(l);
    ll now = (1<<i);
    if(r%now<k){
        forr--;
    }
    if(l%now>k){
        forl++;
    }
    
    ll nowans = get(forr)^get(forl-1);
    
    nowans<<=(i);
    ans^=nowans;
    ll st = (l/now) + (l%now>k);

    ll end = (r/now) - (r%now<k);
    if(end < st ){
        cout<<ans<<endl;return;
    }
    ll curr = end - st + 1;
    
    if(curr%2){
        ans^=k;
    }
    cout<<ans<<endl;
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