#include <iostream>
using namespace std;

// #include<unordered_map>
// int sum(int a){
//     if(a == 1){
//         return 1;
//     }
//     return a+sum(a-1);
// }
// int getPairsWithDifferenceK(int *arr, int n, int k) {
// 	// Write your code here
//     unordered_map<int,int> diff;
//     for(int i = 0 ; i<n ; i++){
//         if(diff[arr[i]]>0){
//             diff[arr[i]]++;
//             continue;
//         }
//         diff[arr[i]] = 1;
//     }
    
    
    
//     int num_pair = 0;
    
//     for(int i = 0; i<n; i++){
//         //cout<<diff[arr[i]]<<endl;
//        if(k = 0){
//            cout<<"entered"<<endl;
//            if(diff.at(arr[i])>1){
//                num_pair = num_pair + sum(diff[arr[i]]-1);
//                diff[arr[i]] = 0;
//            }
//        }else{
//            if(diff.at(arr[i]+k)>0){
//                //cout<<diff[arr[i]+k]<<endl;
//                num_pair = num_pair + diff[arr[i]+k];
//            }
//        }

//     }
    
//     return num_pair;
// }
#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(k==0){
            int a=m[arr[i]];
            count+=(a*(a-1))/2;
            m.erase(arr[i]);
        }
        else{
            if(m[arr[i]-k]>0){
                count+=m[arr[i]-k]*m[arr[i]];
                m.erase(arr[i]-k);
            }
        }
        
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
