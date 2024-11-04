#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
//using u128 = unsigned __int128;

i64 get(i64 n) {
    if (n % 4 == 0) {
        return 0;
    } else if (n % 4 == 1) {
        return n - 1;
    } else if (n % 4 == 2) {
        return 1;
    } else {
        return n;
    }
}

void solve() {
    i64 l, r, i, k;
    std::cin >> l >> r >> i >> k;
    r++;
    
    i64 ans = 0;
    // actual l+1 to r+1 xor stored in ans now.
    ans ^= get(r);
    ans ^= get(l);
    
    r = (r - k + (1LL << i) - 1) >> i;
    l = (l - k + (1LL << i) - 1) >> i;
    
    ans ^= get(r) << i;
    ans ^= get(l) << i;
    
    if ((l ^ r) & 1) {
        ans ^= k;
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}