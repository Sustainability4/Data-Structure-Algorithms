#include<queue>
#include<stack>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    if(n == 0 ){
        vector<int> v;
        return v;
    }
    
    priority_queue<int> pq;
    for(int i =0 ; i<k; i++){
        pq.push(arr[i]);
    }
    
    for(int i = k ; i<n ; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    stack<int> s;
    while(pq.size()!=0){
        s.push(pq.top());
        pq.pop();
    }
    
    vector<int> v;
    while(s.size()!=0){
        v.push_back(s.top());
        s.pop();
    }
    
    return v;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}
