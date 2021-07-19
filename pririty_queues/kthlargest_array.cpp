#include <iostream>
#include <vector>
using namespace std;
#include<queue>
int kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    if(n==0){
        return 0;
    }
    
    //minimum heap priority queue
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i =0 ; i<k ; i++){
        pq.push(input[i]);
    }
    
    for(int i = k ; i<n ; i++){
        if(input[i]>pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    
    return pq.top();
}

int kthLargest(int* arr, int n, int k) {
    // Write your code here
    
    int a = kLargest(arr,n,k);
    return a;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}
