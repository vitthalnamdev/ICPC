#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Define the segment tree and lazy arrays
vector<int> t;
vector<int> lazy;

// Build the segment tree
void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2 + 1]);
    }
}

// Push updates to the children
void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

// Update the segment tree in the range [l, r]
void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

// Query the maximum value in the range [l, r]
int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l == tl && tr == r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    // Example array
    vector<int> a = {1, 3, -2, 8, -7};

    // Initialize the segment tree and lazy arrays
    int n = a.size();
    t.resize(4 * n);
    lazy.resize(4 * n, 0);

    // Build the segment tree
    build(a, 1, 0, n - 1);

    // Update the segment tree
    update(1, 0, n - 1, 1, 3, 3);

    // Query the segment tree
    int result = query(1, 0, n - 1,  0 , 1);
    cout << "Maximum value in the range [2, 4]: " << result << endl;

    return 0;
}
