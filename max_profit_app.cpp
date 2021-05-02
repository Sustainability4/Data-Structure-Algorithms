#include <iostream>
using namespace std;

void quicks(int*arr, int si, int ei){
    if(si >= ei){
        return;
    }
    int key = arr[si];
    int k = si;
    for(int i = si+1 ; i<=ei ; i++){
        if(arr[i] <= key){
            k++;
        }
    }
    arr[si] = arr[k];
    arr[k] = key;
    int i =si;
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
    quicks(arr, si, k-1);
    quicks(arr, k+1,ei);
}

int maximumProfit(int budget[], int n) {
    // Write your code here
    int si = 0;
    int ei = n-1;
    quicks(budget,si,ei);
    int sum = 0;
    for(int i =0; i<n; i++){
        int k = budget[i]*(n-i);
        if(k>=sum){
            sum = k;
        }
    }
    return sum; 

}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
