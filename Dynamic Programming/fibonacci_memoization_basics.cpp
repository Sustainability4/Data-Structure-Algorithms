#include <iostream>
using namespace std;
//Memoization 
int fibonacci_helper(int n, int*ans){
    if(n<= 1){
        return n;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int a = fibonacci_helper(n-1, ans);
    int b = fibonacci_helper(n-2, ans);
    ans[n] = a+b

    return ans[n];
}

int fibonacci_2(int n){
    int*ans = new int[n+1];
    for(int i = 0 ; i<n+1 ; i++){
        ans[i] = -1;
    }
    return fibonacci_helper(n,ans);
}

//Memoization using iteration : Dynamic Programming Bottoms-Ups approach 
// We are moving from small problem to big problem  
int fibonacci_3(int n){
    int * ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2 ; i<n+1 ; i++){
        ans[i] = ans[i-1]+ans[i-1];
    }

    return ans[n];
}
int main() {
    cout<<"Hello World!";
}
