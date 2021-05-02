#include <iostream>
#include <algorithm>
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


void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Write your code here
    quicks(arr1,0, n-1);
    quicks(arr2,0,m-1);
    
    int i = 0;
    int j =0;
    
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }else if (arr2[j]<arr1[i]){
            j++;
        }else{
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}
