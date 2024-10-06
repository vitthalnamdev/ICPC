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
    ll n;
    cin >> n;
    vector<ll> ans;
    int cnt = 0;
    for (int i = 63; i >= 0; i--)
    {
        ll now = ((1LL << i) & n);
        if (now)
        {
            cnt++;
        }
    }
    if(cnt==1){
        cout<<1<<endl<<n<<endl;return;
    }
    for (int i = 0; i <= cnt; i++)
    {
        ll curr = 0;
        int cnt1 = 0;
        for (int j = 0; j <= 63; j++)
        {
            ll now = ((1LL << j) & n);
            if (now)
            {
                cnt1++;
            }
            if (now > 0 && cnt1 > i)
            {
                
                curr |= (now);
            }
            else if (now > 0)
            {
                ll check = (ans.back());
                now = ((now) & (check));
                if (now == 0)
                {
                    curr |= (1LL << j);
                }
            }
        }
        ans.push_back(curr);
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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