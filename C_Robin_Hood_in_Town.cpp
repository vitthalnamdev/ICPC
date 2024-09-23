#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

bool ok(ll mid, ll sum, vector<int>& a) {
    int n = a.size();
    long double p = (long double)(sum + mid) / (n + 0.0);
    p /= 2.0;

    int sp = upper_bound(a.begin(), a.end(), p) - a.begin();
     if(sp==n)sp--;
     while(sp>0&&a[sp]>=p)sp--;
     sp+=1;
    int mp = n / 2;
    return sp > mp;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0LL;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    
    ll low = 0LL;
    ll high = 1e14;
    ll mid;

    if(n<=2){cout<<-1<<endl;return;}
    
    for (int i = 0; i < 60; i++) {
        if (high >= low) {
            mid = (high + low) / 2LL;
            if (ok(mid, sum, a)) high = mid;
            else low = mid;
        }
    }

   
    
    if (ok(high, sum, a)) cout <<high << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
