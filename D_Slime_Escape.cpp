#include <bits/stdc++.h>
using namespace std;
#define ll long long
//(popcount) in the below GCC target.
// #pragma GCC target()
//--------- DEBUG START---------////
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr<< endl;
void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(long long int a ){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr << a;}
template<class T1 , class T2>void _print(pair<T1,T2>a){cerr<<"{ ";cerr<<a.first<<" "<<a.second;cerr<<" }";}
template<class T>void _print(vector<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(set<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(multiset<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
#else
#define debug(x)
#endif
//------DEBUG END---------////
int mod = 1e9+7;
ll inv(ll a)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll prevsum = 0;
    ll aftersum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < k - 1)
        {
            prevsum += (arr[i]);
        }
        else if (i >= k)
        {
            aftersum += (arr[i]);
        }
    }
    debug(prevsum)
    debug(aftersum)
    int p1 = k - 2, p2 = k;
    ll val = arr[k - 1];
    if (abs(prevsum) < abs(aftersum))
    {
        while (p1 >= 0 && p2 < n)
        {
            if (val + arr[p1] >= 0)
            {
                val += arr[p1--];
            }
            else if (val + arr[p2] >= 0)
            {
                val += arr[p2++];
            }
            else
            {
                break;
            }
        }
    }else{
          while (p1 >= 0 && p2 < n)
        {
            if (val + arr[p2] >= 0)
            {
                val += arr[p2++];
            }
            else if (val + arr[p1] >= 0)
            {
                val += arr[p1--];
            }
            else
            {
                break;
            }
        }
    }
    if (p1 < 0 || p2 >= n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
        solve();
    }
}