#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    if(n == 0){
        return true;
    }
    
    int rootIndex;
    int lci;
    int rci;
    for(int i =0 ; i<n ; i++){
        rootIndex = i;
        lci = 2*i+1;
        rci = 2*i+2;
        
        if(lci<n){
            if(lci == n-1){
                if(arr[rootIndex]<arr[lci]){
                    return false;
                    break;
                }
            }else{
                if(arr[rootIndex]<arr[lci]||arr[rootIndex]<arr[rci]){
                    return false;
                    break;
                }
            }
        }else{
            break;
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}
