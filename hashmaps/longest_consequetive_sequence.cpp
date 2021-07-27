/*#include <vector>
#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int, bool> consequent;
    for(int i = 0 ; i<n ; i++){
        int a = arr[i];
        consequent[a] = true;
    }
    int maximum_length = 0;
    int start_point = 0;
    
    for(int i = 0; i<n; i++){
        int p = arr[i];
        int begin_point = 0;
        int length = 0;
        if(consequent.at(p) == false){
            continue;
        }else{
            begin_point = p;
            length = 1;
            consequent.at(p) = false;
            
            while(consequent.find(p+1) != consequent.end() && consequent.at(p+1)){
                consequent.at(p+1) = false;
                length ++;
                p++;
            }
            int q = begin_point;
            while(consequent.find(q-1) != consequent.end() && consequent.at(q-1)){
                consequent.at(q-1) = false;
                length ++;
                begin_point = q-1;
                q--;
            }
        }
        
        if(length>maximum_length){
            start_point = begin_point;
            maximum_length = length;
        }
        
    }
    
    cout<< maximum_length;
    cout<< " "<<start_point;
    
    vector<int> v;
    
    return v;
}
*/

#include<unordered_map>
#include<vector>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int, bool> m;
    vector<int> v;
    
    v.push_back(0);
    v.push_back(0);
    
    for(int i=0;i<n;i++)
    {
        m[arr[i]] = true;
    }
    

    int msp=0;
    int ml=0;
    int mep=0;
    for(int i=0;i<n;i++)
    {
        if(m[arr[i]] == true)
        {
            int tl= 0;
            int tsp = arr[i];
            
            while(m[tsp + tl])
            {
                tl++;
            }
            
            if(tl>ml)
            {
                msp = tsp;
                ml= tl;
                mep = tsp+tl-1;
            }
        }
    }
    
    
   v[0] = msp;
   v[1] = mep;
    
    return v;
}
