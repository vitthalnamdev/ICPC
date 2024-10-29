#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 500;
bool f[N + 1][66];

void solve() {
    int n;
    std::cin >> n;
    
    if (!f[n][0]) {
        std::cout << -1 << "\n";
        return;
    }
    
    int x = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int y : {3, 6}) {
            if (f[i][(x * 10 + y) % 66]) {
                std::cout << y;
                x = (x * 10 + y) % 66;
                break;
            }
        }
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    f[0][0] = true;                 
    for (int i = 1; i <= N; i++) {
        for (int x = 0; x < 66; x++) {
            for (int y : {3, 6}) {
                f[i][x] |= f[i - 1][(x * 10 + y) % 66];
            }
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}