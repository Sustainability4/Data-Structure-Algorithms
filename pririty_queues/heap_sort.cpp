#include<iostream>
using namespace std;

void heapSort(int arr[], int n) {
    // Write your code
    if (n == 0){
        return;
    }
    int rootIndex;
    int p; 
    for(int i=1;i<n; i++){
        p = i;
        while(p>0){
            rootIndex = (p-1)/2;
        	if(arr[rootIndex]>arr[p]){
            	int a = arr[rootIndex];
            	arr[rootIndex] = arr[p];
            	arr[p] = a;
        	}
        	p = rootIndex; 
        }
    }
    
    int lastIndex;
    for(int i = 0 ; i< n; i++){
        lastIndex = n-i-1;
        int a = arr[0];
        arr[0] = arr[lastIndex];
        arr[lastIndex]= a;
        
        int root = 0;
        int lci = 1;
        int rci = 2;
        while(lci<=lastIndex-1){
            if(lci == lastIndex-1){
                if(arr[lci]<arr[root]){
                    int a = arr[root];
                    arr[root] = arr[lci];
                    arr[lci] = a;
                    root = lci;
                    lci = 2*root+1;
                    rci = 2*root+2;
                }else{
                    break;
                }
            }else{
                if(arr[lci]<arr[rci]){
                    if(arr[lci]<arr[root]){
                    	int a = arr[root];
                    	arr[root] = arr[lci];
                    	arr[lci] = a;
                    	root = lci;
                    	lci = 2*root+1;
                    	rci = 2*root+2;
                	}else{
                    	break;
                	}
                }else{
                    if(arr[rci]<arr[root]){
                    	int a = arr[root];
                    	arr[root] = arr[rci];
                    	arr[rci] = a;
                    	root = rci;
                    	lci = 2*root+1;
                    	rci = 2*root+2;
                	}else{
                    	break;
                	}
                }
            }
        }
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
