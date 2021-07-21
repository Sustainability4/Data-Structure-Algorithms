#include<unordered_map>
#include<vector>
#include <iostream>
using namespace std;


int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> freq;
    vector<int> unique_values;
    for(int i = 0; i<n ; i++){
        if(freq.count(arr[i])>0){
            freq[arr[i]] = freq[arr[i]]+1;
            continue;
        }
        
        freq[arr[i]] = 1;
        unique_values.push_back(arr[i]);
    }
    
    pair<int,int> p;
    p.first = unique_values[0];
    p.second = freq[unique_values[0]];
    for(int i = 1; i<unique_values.size();i++){
        if(freq[unique_values[i]]>p.second){
            p.first = unique_values[i];
            p.second = freq[unique_values[i]];
        } 
    }
    
    return p.first;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
