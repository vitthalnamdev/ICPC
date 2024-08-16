// C++ program to demonstrate generate function in STL 
#include <bits/stdc++.h>	 
using namespace std; 

// function to generate random numbers in range [0-999] : 
int randomize() 
{ 
	return (rand() % 51)+1; 
} 

int main () 
{ 
// for different values each time we run the code 
srand(time(NULL)); 
cout<<1<<endl;
int N = 200000;

cout<<N<<endl;
int k = rand()%N;
cout<<k<<endl;
for(int i=0;i<N;i++)
{
      int x = randomize();
      cout<<x<<" ";
}cout<<endl;
return 0; 
} 
