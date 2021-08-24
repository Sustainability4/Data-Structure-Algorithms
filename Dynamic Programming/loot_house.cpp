#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    if(n ==0){
        return 0;
    }
    int*dp_arr = new int[n];
    dp_arr[0] = arr[0];
    dp_arr[1] = max(arr[0],arr[1]);
    for (int i = 2; i<n; i++){
        dp_arr[i] = max(arr[i]+dp_arr[i-2],dp_arr[i-1]);
    }
    
    return dp_arr[n-1];
    
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}
