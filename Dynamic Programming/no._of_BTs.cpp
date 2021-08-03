//Dynamic Programming
#include<cmath>
#include <iostream>
using namespace std;

int balancedBTs(int n) {
    // Write your code here
    int arr[n+1];
    int mod = (int) (pow(10, 9)) + 7;
    
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i = 2; i<n+1 ; i++){
        int x = arr[i-1];
        int y = arr[i-2];
        
        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2* (long)(x) * y) % mod);
        
        int ans = (temp1 + temp2) % mod;
        
        arr[i] = ans;
    }
    
    return arr[n];
    
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
