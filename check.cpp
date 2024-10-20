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

int mod = 1e9+7;

ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
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

// Segment Tree for Range Minimum Query
class SegmentTreeMin {
    vector<int> tree;
    int n;
public:
    SegmentTreeMin(int n) {
        this->n = n;
        tree.assign(4 * n + 4, INT_MAX);
    }
    
    void build(const vector<int>& arr, int l, int r, int ind) {
        if (l == r) {
            tree[ind] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, l, mid, 2 * ind + 1);
        build(arr, mid + 1, r, 2 * ind + 2);
        tree[ind] = min(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    int query(int l, int r, int a, int b, int ind) {
        if (l > b || r < a)
            return INT_MAX;
        if (l >= a && r <= b)
            return tree[ind];
        int mid = (l + r) / 2;
        return min(query(l, mid, a, b, 2 * ind + 1), query(mid + 1, r, a, b, 2 * ind + 2));
    }
};

// Segment Tree for Range Maximum Query
class SegmentTreeMax {
    vector<int> tree;
    int n;
public:
    SegmentTreeMax(int n) {
        this->n = n;
        tree.assign(4 * n + 4, INT_MIN);
    }
    
    void build(const vector<int>& arr, int l, int r, int ind) {
        if (l == r) {
            tree[ind] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, l, mid, 2 * ind + 1);
        build(arr, mid + 1, r, 2 * ind + 2);
        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    int query(int l, int r, int a, int b, int ind) {
        if (l > b || r < a)
            return INT_MIN;
        if (l >= a && r <= b)
            return tree[ind];
        int mid = (l + r) / 2;
        return max(query(l, mid, a, b, 2 * ind + 1), query(mid + 1, r, a, b, 2 * ind + 2));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    string s;
    cin >> s;
    
    SegmentTreeMax segMax(n + 1);
    SegmentTreeMin segMin(n + 1);
    segMax.build(arr, 1, n, 0);
    segMin.build(arr, 1, n, 0);
    
    set<pair<int, int>> segments;
    int prev = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != s[prev - 1]) {
            segments.insert({prev, i - 1});
            prev = i;
        }
    }
    segments.insert({prev, n});
    
    auto canSort = [&](int l, int r) {
        int minVal = segMin.query(1, n, l, r, 0);
        int maxVal = segMax.query(1, n, l, r, 0);
        return (minVal == l && maxVal == r);
    };
    
    while (q--) {
        int ind;
        cin >> ind;
        s[ind - 1] = (s[ind - 1] == 'L' ? 'R' : 'L');
        
        auto it = segments.lower_bound({ind, 0});
        if (it != segments.end() && it->first <= ind && it->second >= ind) {
            auto [segStart, segEnd] = *it;
            segments.erase(it);
            
            if (segStart <= ind - 1) {
                segments.insert({segStart, ind - 1});
            }
            if (ind + 1 <= segEnd) {
                segments.insert({ind + 1, segEnd});
            }
        }
        
        bool possible = true;
        for (const auto& [l, r] : segments) {
            if (!canSort(l, r)) {
                possible = false;
                break;
            }
        }
        
        cout << (possible ? "YES" : "NO") << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
