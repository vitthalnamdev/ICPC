#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mod = 998244353;
const int inf = 2e18;

struct my_hash {
    size_t operator()(const pair<int, int>& a) const {
        return a.first * 11 + a.second;
    }
};

vector<vector<int>> g;
vector<int> d, d_all;

void dfs(int v, int p) {
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        d[v] = max(d[v], d[to] + 1);
    }
}

void reroot(int v, int p, int d_up) {
    d_all[v] = max(d[v], d_up);
    vector<int> sons;
    int max1 = -inf, max2 = -inf;
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        sons.push_back(to);
        if (max1 < d[to]) {
            max2 = max1;
            max1 = d[to];
        } else if (max2 < d[to]) {
            max2 = d[to];
        }
    }
    for (int to: sons) {
        reroot(to, v, max(d_up + 1, (d[to] == max1 ? max2 : max1) + 2));
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    d.resize(n);
    dfs(0, -1);
     
    d_all.resize(n);
    reroot(0, -1, 0);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[d_all[i]]++;
    }
    for (int i = n; i > 0; i--) {
        cnt[i - 1] += cnt[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << min(n + 1 - cnt[i], n) << ' ';
    }
}