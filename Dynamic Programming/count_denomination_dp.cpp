#include <iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
    int **arr = new int*[numDenominations+1];
    for(int i = 0; i<numDenominations+1; i++){
        arr[i] = new int[value+1];
    }
    
    for(int i = 0; i<numDenominations+1; i++){
        arr[i][0] = 1;
    }
    
    for(int i = 0; i<value+1; i++){
        arr[0][i] = 0;
    }
    
    for(int i = 1 ; i<numDenominations+1; i++){
        for(int j = 1; j<value+1; j++){
            int x = arr[i-1][j];
            int y = 0;
            if(j-i >=0){
                y = arr[i][j-i];
            }
            
            arr[i][j] = x+y;
        }
    }
    
    return arr[numDenominations][value];
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}
