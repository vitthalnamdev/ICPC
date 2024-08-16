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
bool check(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j])
                return true;
        }
    }
    return false;
}
void yeh_bhi_krr_lete_hain()
{
    int n, q;
    cin >> n >> q;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sort(arr[i].begin(), arr[i].end());
    }
    map<string, set<int>> s;
    for (int i = 0; i < n; i++)
    {
        s[arr[i]].insert(i);
    }
    vector<char> colors = {'G', 'B', 'Y', 'R'};

    while (q--)
    {
        int value[2];
        cin >> value[0] >> value[1];
        sort(value, value + 2);
        int a = value[0] - 1;
        int b = value[1] - 1;

        int ans = INT_MAX;
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < 4; i++)
            {

                

                string now = "";
                now += (arr[a][j]);
                now += (colors[i]);

                sort(now.begin(), now.end());
                if (!check(now, arr[b]))
                {
                    continue;
                }
                auto curr = s[now].lower_bound(a);

                if (s[now].size() == 0)
                {
                    continue;
                }
                if (curr == s[now].end())
                {
                    curr--;
                    ans = min(ans,  abs(b + a - *curr - *curr));
                    continue;
                }
                  auto newvar = curr;
                
                    ans = min(ans, abs(*curr + *curr - a - b));
                    if(curr==s[now].begin()){
                        continue;
                    }
                    curr--;
                    ans = min(ans , abs(*curr + *curr - a - b));
            }
        }
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                // if(arr[b][j]==colors[i]){
                //    continue;
                // }

                string now = "";
                now += (arr[b][j]);
                now += (colors[i]);
                sort(now.begin(), now.end());
                if (!check(now, arr[a]))
                {
                    continue;
                }
                auto curr = s[now].lower_bound(a);
                if (s[now].size() == 0)
                {
                    continue;
                }
                 
                 if(curr!=s[now].end()){
                    ans = min(ans, abs(*curr + *curr - a - b));
                 }
                if(curr==s[now].begin()){
                   ans = min(ans ,abs( *curr + *curr - a - b));
                    continue;
                }
                curr--;
                
                    ans = min(ans,abs( b + a - *curr - *curr));
                 
            }
        }
        if (ans == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
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
        yeh_bhi_krr_lete_hain();
    }
}