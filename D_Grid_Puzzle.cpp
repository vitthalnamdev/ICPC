#include <bits/stdc++.h>
using namespace std;

#define int ll

using ll = long long;
using pii = pair<int, int>;

#define debug(x) cerr << #x <<" "; _print(x); cerr<< endl;
void _print(char a){cerr<<a;}
void _print(long long a ){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr << a;}
template<class T1 , class T2>void _print(pair<T1,T2>a){cerr<<"{ ";cerr<<a.first<<" "<<a.second;cerr<<" }";}
template<class T>void _print(vector<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(set<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(multiset<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
const int N = 2e5 + 20, inf = 3e18 + 20;
int n, arr[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
    vector<vector<int>>dp(n+1  , vector<int>(4));
		for (int i = 0; i < n; i++) cin >> arr[i];

		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 4; j++)
				dp[i][j] = inf;

		dp[0][0] = 0;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][0] + (arr[i - 1] > 0);

			if (i == 1) {
				if (arr[i - 1] <= 2) dp[i][1] = 1;
				continue;
			}

			if (arr[i - 1] >= 5) continue;
           
			dp[i][0] = min(dp[i][0], dp[i - 1][3]);
         
			dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
			dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
         
			dp[i][3] = min(dp[i][3], dp[i - 1][0] + 2);

			if (arr[i - 1] <= 2) {
				dp[i][0] = min(dp[i][0], dp[i - 1][1]);
				dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
			}

		 	// cout << ' ' << i << '\t' << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << '\n';
		}
        debug(dp);
		cout << dp[n][0] << '\n';
	}
}
