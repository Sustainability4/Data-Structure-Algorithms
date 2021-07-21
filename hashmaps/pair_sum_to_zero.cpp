#include <iostream>
using namespace std;
#include<unordered_map>

int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> hash;
    
    for(int i = 0 ; i<n ; i++){
        ++hash[arr[i]];
    }
    
    int product = 0;
    for(int i = 0; i<n; i++){
        if(hash[arr[i]]>0 && hash[-arr[i]]>0){
            if(arr[i] == -arr[i]){
                product = product+((hash[arr[i]])*(hash[arr[i]]-1))/2;
                hash[arr[i]] = 0;
            }else{
                product = product + hash[arr[i]]*hash[-arr[i]];
                hash[arr[i]] = 0;
            	hash[-arr[i]] = 0;
            }
            
            
        }
    }
    return product;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
