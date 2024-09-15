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
int cnt = 0;
void solve()
{
    cnt++;
    int n, k;
    cin >> n >> k;
    vector<int> num(k);
    for (int i = 0; i < k; i++)
        cin >> num[i];
    vector<int> coins(k);
    for (int i = 0; i < k; i++)
        cin >> coins[i];
    
    for(int i=0;i<k;i++){
        if(num[i]<coins[i]){
            cout<<"NO"<<endl;return;
        }
        if(i>=1 && num[i]-num[i-1]<coins[i]-coins[i-1]){
           cout<<"NO"<<endl;return;
        }
    }
    cout<<"YES"<<endl;
    char val = 'c';
    int prev = 0;
    string ans = "abc";
    vector<char>help = {'a' , 'b' , 'c'};
    int p1 = 0;
    int curr = 3;
    int prevcoins = 0;
    int ele;
    for(int i=0;i<k;i++){
        ele = num[i] - curr - prev;
        int currcoins = coins[i] - prevcoins;
        while(ele>0){
            ele--;
            if(curr>=currcoins){
              ans+=help[p1++];
              p1%=3;
            }else{
              ans+=val;
            }
            curr++;
        }
        curr = 0;
        val++;
        prev = num[i];
        prevcoins = coins[i];
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