#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>dp(n+1,0);
  vector<int>val(100010 , 0);
  vector<int>count(100010 , 0); 
  dp[0] = 0;
  val[arr[0]] = 0;
  count[arr[0]]++;
  for(int i=1;i<n;i++){
     dp[i] = dp[i-1] + 1;
     if(val[arr[i]]!=0)
     val[arr[i]] = min(val[arr[i]] , dp[i]);
     else 
     val[arr[i]] = dp[i];
     int check = INT_MAX;
     for(int j = 1;j<=sqrt(arr[i]);j++){
        if(arr[i]%j==0){
         
            if(count[j]>0)
            check = min(check , val[j] + j);
            int now = arr[i]/j;
            if(count[now]>0){
             check = min(check , val[now] + now);
            }
        }
     }
     if(check!=INT_MAX){
       if(val[arr[i] + 1]==0)
       val[arr[i]+1]  = check;
       else 
       val[arr[i] + 1] = min(val[arr[i] + 1] , check);
     }

     count[arr[i]]++;

     if(check!=INT_MAX){
       count[arr[i]+1]++;
     }
     dp[i] = min(dp[i] , check);
  }
   
  cout<<dp[n-1]<<endl;
}