// C++ program to demonstrate generate function in STL 
#include <bits/stdc++.h>	 
using namespace std; 

// function to generate random numbers in range [0-999] : 
int randomize() 
{ 
	return (rand()); 
} 

int main () 
{ 
// for different values each time we run the code 
srand(time(NULL)); 
int x = randomize()%80;
if(x<10){
	x+=10;
}
 cout<<x<<" ";
 int n = 300000;
 set<int>s;
 for(int i=0;i<n;i++){
	int xx =i , h;
	 
	h = 1000;
	if(h==0)h++;
	cout<<xx<<" "<<h<<endl;
 }
 
} 
