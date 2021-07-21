#include <iostream>
using namespace std;
#include<unordered_map>
#include<queue>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int, int> intersection;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i =0 ; i<n; i++){
        if(intersection[arr1[i]]>0){
            intersection[arr1[i]] = intersection[arr1[i]]+1;
            continue;
        }
        
        intersection[arr1[i]] = 1;
    }
    
    for(int i = 0; i<m ; i++){
        if(intersection[arr2[i]]>0){
            pq.push(arr2[i]);
            intersection[arr2[i]] = intersection[arr2[i]]-1;
        }
    }
    
    while(pq.size() != 0){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
