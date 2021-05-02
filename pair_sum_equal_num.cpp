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

int bins(int*arr, int si, int ei, int key){
    if(si==ei){
        if(arr[ei]==key){
            return 1;
        }else {
            return 0;
        }
    }
    if(si>ei){
        return 0;
    }
    int k =0;
    int mid = (si+ei)/2;
    
    if(arr[mid]==key){
        int b = bins(arr,si,mid-1,key);
        int c = bins(arr, mid+1,ei,key);
        k = k+b+c+1;
        
    }else if( arr[mid]>key){
        int b = bins(arr,si,mid-1,key);
        k = k+b;   
    }else{
        int c = bins(arr, mid+1,ei,key);
        k = k+c;    
    }
    
    return k ; 
}

int pairSum(int *arr, int n, int num)
{
	//Write your code here
    quicks(arr,0,n-1);
    int sum = 0;
    for(int i =0 ; i<n ; i++){
        if(num > arr[i]){
            int a = bins(arr, i+1, n-1, num-arr[i]);
            sum = sum+a;
        }
    }
    
    return sum;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}
