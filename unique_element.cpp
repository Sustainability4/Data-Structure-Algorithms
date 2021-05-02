#include <iostream>
using namespace std;
// Approach with n square time complexity
int findUnique(int *arr, int n) {
    if(n==1){
        return arr[0];
    }
    int key = arr[0];
    int i = 1;
    while(arr[i]!=key && i<n){
        i++;
    }
    if (i == n){
        return key;
    }else{
        for(int j = i; j<=n;j++){
            arr[j] = arr[j+1];
        }
        n = n-1;
        for(int k =0; k<=n; k++){
            arr[k] = arr[k+1];
        }
        n = n-1;
        int m = findUnique(arr,n);
        return m; 
    }
}

// Approach with n logn  time complexity(quick sort)

void quicks(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }
    int key = arr[si];
    int k = 0;
    for(int i = si+1 ; i<=ei ; i++){
        if(arr[i]<=key){
            k++;
        }
    }
    arr[si] = arr[k];
    arr[k] = key;
    
    int i = si;
    int j = k+1;
    
    while(i<k && j<=ei){
        if(arr[i]<=key){
            i++;
        }else if (arr[j] > key){
            j++;
        }else{
            int m = arr[i];
            arr[i] = arr[j];
            arr[j] = m;
            i++;
            j++;
        }
    }
    quicks(arr,si,k-1);
    quicks(arr,k+1,ei);
}

int unique(int arr[], int n){
    int i =0;
    while(i<n){
        if(arr[i]==arr[i+1]){
            i = i+2;
        }else{
            break;
        }
    }
    return arr[i];
}


int findUnique(int *arr, int n) {
    int si = 0;
    int ei = n-1;
    quicks(arr,si,ei);
    int m = unique(arr,n);
    return m;
}

// Time complexity of n approach (Using XOR operator)
int findUnique(int *arr, int n) {
    int m = arr[0];
    for(int i =1 ; i<n ;i++){
        m = m^arr[i];
    }
    return m;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}
