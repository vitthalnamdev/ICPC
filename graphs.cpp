#include<bits/stdc++.h>
using namespace std;

queue<int>q;
queue<int>q2;
  void push(int x) {
        if(q.size()==0){
            q.push(x);
            return;
        }
        int top = q.front();
        q.pop();
        push(x);
        q.push(top); 
    }
int main(){
    // int n;cin>>n;int m;cin>>m;
     push(1);
     push(2);
    //  push(3);
     while(!q.empty())
     {
        cout<<q.front()<<" ";q.pop();
     }cout<<endl;
}