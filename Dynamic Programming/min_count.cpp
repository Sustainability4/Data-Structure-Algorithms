#include<cmath>
#include <bits/stdc++.h>
using namespace std;
/*int minCounthelper(int n, int *arr)
{
	//Write your code here
    if(n == 1){
        arr[n] = 1;
        return arr[1];
    }
    
    if(n == 0){
        arr[0] = 0;
        return arr[0];
    }
    int root = sqrt(n);
    int count = 9999999;
    for(int i = 1 ; i<=root ; i++){
        int value;
        if(arr[n-(i*i)] != -1){
            value = arr[n-(i*i)];
        }else{
            value = minCounthelper(n-(i*i),arr);
        }
        
        if(value<count){
            arr[n] = count;
            count = value;
        }
    }
    
    return count+1;
}
*/

int minCount(int n){
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i = 2 ; i<n+1; i++){
        int count = 999999;
        for(int j = 1 ; j<=sqrt(i); j++){
            int value = arr[i-(j*j)];
            if(value<count){
                count = value;
            }
        }
        arr[i] = count+1;
    }
    return arr[n] ;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
