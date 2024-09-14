// Don't look the rank , if you want a good rank
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
vector<string>arr;
vector<int>s[17];
vector<char> colors = {'G', 'B', 'Y', 'R'};
int f[100];

int hash_func(string a ){
   return f[a[0]] + f[a[1]];   
}
inline void query()
{
    int ans = 1e9;
    int ind[2];
    cin >> ind[0] >> ind[1];
    ind[0]--;
    ind[1]--;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (arr[ind[0]][j] == arr[ind[1]][i])
            {
                cout << abs(ind[0] - ind[1]) << endl;
                return;
            }
        }
    }
    for(int j=0;j<2;j++){
        for(int i=0;i<4;i++){
            if(colors[i]==arr[ind[0]][0] || colors[i]==arr[ind[0]][1]){continue;}  
            // now , try to find lowerbound and upperbound;
             string str = "";
             str+=(arr[ind[0]][j]);str+=(colors[i]);
             sort(str.begin() , str.end());
             int curr = hash_func(str);
            //cout<<curr<<endl;
            auto low =  upper_bound(s[curr].begin() , s[curr].end() , ind[1]);
            auto upp = low;
            if(low!=s[curr].begin()){
                low--;
                ans = min(ans , abs(*low - ind[0]) + abs(*low - ind[1]));
            }
            if(upp!=s[curr].end()){
               ans = min(ans , abs(*upp - ind[0]) + abs(*upp - ind[1]));
            }
        }
    }
    if(ans==1e9){
        cout<<-1<<endl;return;
    }
    cout<<ans<<endl;
}


void yeh_bhi_krr_lete_hain()
{
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for(int i=1;i<=16;i++)s[i].clear();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sort(arr[i].begin(), arr[i].end());
    }
     
    for (int i = 0; i < n; i++)
    {
        s[hash_func(arr[i])].push_back(i);
    }

    while (q--)
    {
        query();
    }
}
int main()
{
    f['R'] = 8;
    f['G'] = 1;
    f['Y'] = 4;
    f['B'] = 2;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        yeh_bhi_krr_lete_hain();
    }
}