#include <iostream>
using namespace std;
int staircase(int n){
    if (n == 0){
        return 1;
    }
    int d = 0;
    int e = 0;
    int f = 0;
    if (n >= 1){
        d = staircase(n-1);
    }
    if (n >= 2){
        e = staircase(n-2);
    }
    if (n >= 3){
        f = staircase(n-3);
    }
    return d+e+f ; 
    
}
int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
