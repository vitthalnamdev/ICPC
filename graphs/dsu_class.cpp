#include<bits/stdc++.h>
using namespace std;
class DSU{
  public:
  int n;
  int* parent; int *rank;
  DSU(int sz){
     n= sz;
    parent = new int[200005];
    rank = new int[200005];
    for(int i=1;i<=n;i++)parent[i]=i,rank[i] = 0;
  }
  int find(int a){
     if(parent[a]==a){return a;}
     return find(parent[a]);
  }
 
  bool merge(int a, int b){
    
     int parenta = find(a);int parentb = find(b);
     if(parenta == parentb){return false;}
     if(rank[parenta]>rank[parentb]){
        parent[parentb] = parenta;
     }else if(rank[parentb]> rank[parenta]){
        parent[parenta] = parentb;
     }
     else{
        parent[parentb] = parenta;
        rank[parenta]++;
     }
     return true;
  }
 
};

int main(){

}