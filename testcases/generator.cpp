#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[] ) {
   srand(atoi(argv[1]));
    cout<<1<<endl;
    int n = rand()%200000;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        int x = rand()%26;
        char now = x+'a';
        cout<<now;
    }
    cout<<endl;
    return 0;
}
