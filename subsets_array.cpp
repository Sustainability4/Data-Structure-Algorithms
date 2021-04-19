// For eg. Input : {1, 2}, then output should contain 
	// {{0}, 		// Length of this subset is 0
	// {1, 2},		// Length of this subset is 1
	// {1, 1},		// Length of this subset is also 1
	// {2, 1, 2}}	// Length of this subset is 2

// Don’t print the subsets, just save them in output.
// ***/
#include<iostream>
using namespace std;
int subset(int input[], int n, int output[][20]) {
    if (n == 0){
        output[0][0] = 0;
        return 1; 
    }
    int length = subset(input+1, n-1, output);
    int i = 0;
    for(i; i<length; i++){
        for(int j = output[i][0] ; j>=0 ; j--){
            output[i+length][j]= output[i][j];
        }
        for ( int j = output[i+length][0]; j>=1 ; j--){
            output[i+length][j+1] = output[i+length][j];
        }
        output[i+length][1] = input[0];
        output[i+length][0] += 1;
    }
    return i+length;

}
int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
