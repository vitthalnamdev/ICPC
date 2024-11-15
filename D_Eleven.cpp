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
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
     
     

    int total = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')total++;
    }
    int fz = 0;
    int lz = 0;
    int in1 = 0;
    int in2 = 0;
    for (in1 = 0; in1 < n; in1++)
    {
        if (s[in1] == '0')
            fz++;
        else
            break;
    }
    for (in2 = n - 1; in2 >= 0; in2--)
    {
        if (s[in2] == '0')
            lz++;
        else
            break;
    }
    int cnt;
    char prev;
    vector<int> add;
    if (in1 < n)
    {
        prev = s[in1];
        cnt = 0;
        for (int i = in1; i <= in2; i++)
        {
            if (s[i] != prev)
            {
                if (prev == '0')
                {
                    add.push_back(cnt);
                }
                prev = s[i];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        
    }
    sort(add.begin() , add.end());
 
    int f = 0;
    int l = 0;
    int ind1 = 0;
    int ind2 = 0;
    for (ind1 = 0; ind1 < n; ind1++)
    {
        if (s[ind1] == '1')
            f++;
        else
            break;
    }
    for (ind2 = n - 1; ind2 >= 0; ind2--)
    {
        if (s[ind2] == '1')
            l++;
        else
            break;
    }
    vector<int> remove;
    if (ind1 < n)
    {
        prev = s[ind1];
        cnt = 0;
        for (int i = ind1; i <= ind2; i++)
        {
            if (s[i] != prev)
            {
                if (prev == '1')
                {
                    remove.push_back(cnt);
                }
                prev = s[i];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        
    }

    sort(remove.begin() , remove.end() , greater<int>());
    set<int>check;
    for(int i=0;i<remove.size();i++){
          check.insert(i);
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
     if(s[i]=='1' && s[i+1]=='1')ans++;
    }
    int padd = 0 , premove = 0;
    int psz = add.size();int removesz = remove.size();
    
    for(int i=0;i<=n;i++){
       if(i==0){
         cout<<ans<<" ";continue;
       }
       if(padd<psz){
        total++;
          add[padd]--;
          if(add[padd]==0){
            if(total>1)
             ans+=2;
             padd++;
          }else{
            ans++;
          }
       }else if(fz>0){
        total++;
           fz--;
           if(total>1)
           ans++;
        }else if(lz>0){
            total++;
           lz--;
           if(total>1)
           ans++;
        }else{
          if(f>0){
             f--;ans--;
          }else if(l>0){
             l--;ans--;
          }else if(premove<remove.size()){
             auto it = check.find(premove);
             if(it!=check.end()){ans-=2;check.erase(it);} 
             else ans--;
             remove[premove]--;
             if(remove[premove]==0){
                premove++;
             }
          }
       }
       cout<<max(0 , ans)<<" ";
    }
    cout<<endl;
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