#include <iostream>
using namespace std;

/*int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int * output = new int[n];
    output[0] = 1;
    
    for(int i = 1; i<n ; i++){
        output[i] = 1;
        for(int j = i-1 ; j>=0 ; j++){
            if(arr[j]<=arr[i]){
                int newoutput = 1+output[j];
                if(newoutput>output[i]){
                    output[i] = newoutput;
                }
            }
        }
    }
    int best = 0;
    for(int i = 0; i<n; i++){
        if(output[i]>best){
            best = output[i];
        }
    }
    
    delete [] output;
    return best;
}*/
int _lis(int*arr, int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int longestIncreasingSubsequence(int*arr, int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
